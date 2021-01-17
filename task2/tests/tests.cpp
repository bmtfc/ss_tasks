//
// Created by Mac on 17.01.2021.
//

#include "gtest/gtest.h"
#include "/Users/mac/softserve/ss_tasks/task2/src/AnyType.h"
#include "/Users/mac/softserve/ss_tasks/task2/src/AnyTypeExceptions.h"


TEST(method_to_type, test_bool)
{
    AnyType x(true);
    EXPECT_EQ(true, x.ToBool());
}

TEST(method_to_type, test_int)
{
    AnyType x(4);
    EXPECT_EQ(4, x.ToInt());
}

TEST(method_to_type, test_usingned_int)
{
    unsigned data = 2;
    AnyType x(data);
    EXPECT_EQ(2, x.ToUnsignedInt());
}

TEST(method_to_type, test_long_int)
{
    long data = 100;
    AnyType x(data);
    EXPECT_EQ(100, x.ToLongInt());
}

TEST(method_to_type, test_float)
{
    float data = 3.5;
    AnyType x(data);
    EXPECT_EQ(3.5, x.ToFloat());
}

TEST(method_to_type, test_double)
{
    double data = 25.8;
    AnyType x(data);
    EXPECT_EQ(25.8, x.ToDouble());
}

TEST(method_to_type, test_long_double)
{
    long double data = 125.8;
    AnyType x(data);
    EXPECT_EQ(125.8, x.ToLongDouble());
}

TEST(method_to_type, test_char)
{
    char data = 'a';
    AnyType x('a');
    EXPECT_EQ('a', x.ToChar());

}

TEST(special, none)
{
    AnyType x(2);
    x.Destroy();
    ASSERT_ANY_THROW(x.ToBool());
    ASSERT_ANY_THROW(x.ToInt());
    ASSERT_ANY_THROW(x.ToUnsignedInt());
    ASSERT_ANY_THROW(x.ToLongInt());
    ASSERT_ANY_THROW(x.ToFloat());
    ASSERT_ANY_THROW(x.ToDouble());
    ASSERT_ANY_THROW(x.ToLongDouble());
    ASSERT_ANY_THROW(x.ToChar());
}

TEST(special, setters)
{
    AnyType x(2);
    x.SetValue(true);
    EXPECT_STREQ("bool", x.GetType());
    x.SetValue(4);
    EXPECT_STREQ("int", x.GetType());
    unsigned int data1 = 6;
    x.SetValue(data1);
    EXPECT_STREQ("unsigned int", x.GetType());
    long int data2 = 16;
    x.SetValue(data2);
    EXPECT_STREQ("long int", x.GetType());
    float data3 = 2.3;
    x.SetValue(data3);
    EXPECT_STREQ("float", x.GetType());
    double data4 = 6.4;
    x.SetValue(data4);
    EXPECT_STREQ("double", x.GetType());
    long double data5 = 19.3;
    x.SetValue(data5);
    EXPECT_STREQ("long double", x.GetType());
    char data6 = 97;
    x.SetValue(data6);
    EXPECT_STREQ("char", x.GetType());

}

TEST(special, swap)
{
    AnyType x(2.3);
    AnyType y(3.4);
    x.SwapWith(y);
    EXPECT_EQ(3.4, x.ToDouble());
    EXPECT_EQ(2.3, y.ToDouble());
}

TEST(special, operators)
{
    AnyType x(2);
    x = (true);
    EXPECT_STREQ("bool", x.GetType());
    x = (4);
    EXPECT_STREQ("int", x.GetType());
    unsigned int data1 = 6;
    x = (data1);
    EXPECT_STREQ("unsigned int", x.GetType());
    long int data2 = 16;
    x = (data2);
    EXPECT_STREQ("long int", x.GetType());
    float data3 = 2.3;
    x = (data3);
    EXPECT_STREQ("float", x.GetType());
    double data4 = 6.4;
    x = (data4);
    EXPECT_STREQ("double", x.GetType());
    long double data5 = 19.3;
    x = (data5);
    EXPECT_STREQ("long double", x.GetType());
    char data6 = 97;
    x = (data6);
    EXPECT_STREQ("char", x.GetType());

}