#include <gtest/gtest.h>
#include "../src/03-findDuplicate.cpp"

TEST(blatest,test1){
    EXPECT_EQ (findDuplicate::findDuplicate2({2,3,5,4,1,2,6,7}),2);

    
    EXPECT_EQ (findDuplicate::findDuplicate2({2,3,5,4,1,3,6,7}),3);

    EXPECT_EQ (findDuplicate::findDuplicate2({2,3,5,4,1,6,6,7}),6);

    EXPECT_EQ (findDuplicate::findDuplicate2({1,1,2}),1);

    EXPECT_EQ (findDuplicate::findDuplicate2({}),-1);

    EXPECT_EQ (findDuplicate::findDuplicate2({0,0}),0);

    EXPECT_EQ (findDuplicate::findDuplicate2({1,1}),1);

    EXPECT_EQ (findDuplicate::findDuplicate2({0,1}),-1);

    EXPECT_EQ (findDuplicate::findDuplicate2({0,1,3,2,4,6,5}),-1);

    EXPECT_EQ (findDuplicate::findDuplicate2({0,1,2,3,4,5,1,2}),1);

    EXPECT_EQ (findDuplicate::findDuplicate2({0,2}),-1);

    // EXPECT_EQ (max(4,3),4);

}