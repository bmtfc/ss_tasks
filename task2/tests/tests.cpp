//
// Created by Mac on 17.01.2021.
//

#include "gtest/gtest.h"
#include "/Users/mac/softserve/ss_tasks/task2/src/AnyType.h"

TEST(firstTest, test1){
    AnyType x(4);
    EXPECT_EQ(4,x.ToInt());
    ASSERT_ANY_THROW(x.ToBool());
}