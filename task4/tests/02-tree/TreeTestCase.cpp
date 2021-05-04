//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
TEST(Tree, TestCase) {
    boost::filesystem::create_directory("./TreeTestCaseTmpDir");
    boost::filesystem::create_directory("./TreeTestCaseTmpDir/inner");
    std::ofstream file("./TreeTestCaseTmpDir/file.txt");
    EXPECT_THROW(GetTree("./TreeTestCaseTmpDirNO", false), std::invalid_argument);
    EXPECT_THROW(GetTree("./TreeTestCaseTmpDir/file.txt", false), std::invalid_argument);
    auto node1 = GetTree("./TreeTestCaseTmpDir", true);
    auto node2 = GetTree("./TreeTestCaseTmpDir", false);
    EXPECT_FALSE(node1 == node2);
    EXPECT_EQ(node1.name, "TreeTestCaseTmpDir");
    EXPECT_EQ(node2.name, "TreeTestCaseTmpDir");
    EXPECT_TRUE(node1.is_dir);
    EXPECT_TRUE(node2.is_dir);
    for (auto& sn : node1.children) {
        if (sn.is_dir) {
            EXPECT_EQ(sn.name, "inner");
            EXPECT_EQ(sn.children.size(), 0);
        } else {
            EXPECT_EQ(sn.name, "file.txt");
        }
    }
    FilterEmptyNodes(node2, "./TreeTestCaseTmpDir");
    EXPECT_FALSE(boost::filesystem::exists("./TreeTestCaseTmpDir/inner"));
    boost::filesystem::remove_all("TreeTestCaseTmpDir");
}
