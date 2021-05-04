//
// Created by akhtyamovpavel on 5/1/20.
//

#include <stdexcept>
#include "AddTestCase.h"
#include "Functions.h"

TEST(A, B) {
    ASSERT_EQ(Add(2, 2), 4);

    ASSERT_THROW(IsLeap(-1), std::invalid_argument);
    ASSERT_FALSE(IsLeap(3));
    ASSERT_TRUE(IsLeap(4));
    ASSERT_FALSE(IsLeap(200));
    ASSERT_TRUE(IsLeap(400));

    ASSERT_EQ(GetMonthDays(4, 2), 29);
    ASSERT_EQ(GetMonthDays(3, 2), 28);
    ASSERT_THROW(GetMonthDays(4, -1), std::invalid_argument);
    ASSERT_EQ(GetMonthDays(4, 4), 30);
    ASSERT_EQ(GetMonthDays(4, 5), 31);
}