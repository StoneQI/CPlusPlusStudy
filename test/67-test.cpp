#include <gtest/gtest.h>
#include "../src/67-cutRope.cpp"

TEST(swardoffer,cutRope){
    Solution solution;
    EXPECT_EQ(solution.cutRope(8),18);
    EXPECT_EQ(solution.cutRope(4),4);


}