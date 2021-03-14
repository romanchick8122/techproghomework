#include <gtest/gtest.h>
#include <B/lib.h>
#include <A/index.h>

TEST(min, MinIntegers) {
  EXPECT_EQ(1, min(1, 3));
  EXPECT_EQ(1000000007, min(1000000007, 1000000008));
  EXPECT_EQ(-6, mul(-6, 100));
}

TEST(max, MaxIntegers) {
    EXPECT_EQ(3, max(1, 3));
    EXPECT_EQ(1000000008, max(1000000007, 1000000008));
    EXPECT_EQ(100, max(-6, 100));
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
