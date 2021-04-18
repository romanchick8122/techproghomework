//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
void TreeTestCase::SetUp() {
    boost::filesystem::create_directory("./TreeTestCaseTmpDir");
    boost::filesystem::create_directory("./TreeTestCaseTmpDir/inner");
    std::ofstream file("./TreeTestCaseTmpDir/file.txt");
}
void TreeTestCase::TearDown() {
    boost::filesystem::remove_all("TreeTestCaseTmpDir");
}
TEST_F(TreeTestCase, A) {
    ASSERT_THROW(GetTree("./TreeTestCaseTmpDirNO", false), std::invalid_argument);
    ASSERT_THROW(GetTree("./TreeTestCaseTmpDir/file.txt", false), std::invalid_argument);
    auto node1 = GetTree("./TreeTestCaseTmpDir", true);
    auto node2 = GetTree("./TreeTestCaseTmpDir", false);
    ASSERT_EQ(node1.name, "TreeTestCaseTmpDir");
    ASSERT_EQ(node2.name, "TreeTestCaseTmpDir");
    ASSERT_TRUE(node1.is_dir);
    ASSERT_TRUE(node2.is_dir);
    for (auto& sn : node1.children) {
        if (sn.is_dir) {
            ASSERT_EQ(sn.name, "inner");
            ASSERT_EQ(sn.children.size(), 0);
        } else {
            ASSERT_EQ(sn.name, "file.txt");
        }
    }

    FilterEmptyNodes(node2, ".");
    ASSER_FALSE(boost::filesystem::exists("./TreeTestCaseTmpDir/inner"));
}