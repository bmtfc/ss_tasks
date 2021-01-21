#include "gtest/gtest.h"
#include "/Users/mac/softserve/ss_tasks/task1/src/StringList.h"
#include "/Users/mac/softserve/ss_tasks/task1/src/StringList.cpp"

TEST(private_methods, size)
{
    char **list;
    StringListInit(&list);
    SetSize(list, 6);
    int y = GetSize(list);
    EXPECT_EQ(6, y);
}

TEST(private_methods, capacity)
{
    char **list;
    StringListInit(&list);
    SetCapacity(list, 4);
    int y = GetCapacity(list);
    EXPECT_EQ(4, y);
}

TEST(public_methods, add)
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "Lorem ipsum dolor sit amet");
    StringListAdd(&list, "consectetur adipiscing elit");
    StringListAdd(&list, "sed do eiusmod tempor incididunt ut");
    StringListAdd(&list, "labore et dolore magna aliqua");
    StringListAdd(&list, "ut enim ad minim veniam");
    EXPECT_STREQ("Lorem ipsum dolor sit amet", list[1]);
}

TEST(public_methods, destroy)
{
    char **list;
    StringListInit(&list);
    StringListDestroy(&list);
    ASSERT_NO_THROW();
}

TEST(public_methods, set_get)
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "Lorem ipsum dolor sit amet");
    StringListAdd(&list, "consectetur adipiscing elit");
    StringListSet(list, 2, "gj");
    char *str = StringListGet(list, 2);
    EXPECT_STREQ("gj", str);
}

TEST(public_methods, size)
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "Lorem ipsum dolor sit amet");
    StringListAdd(&list, "consectetur adipiscing elit");
    EXPECT_EQ(2, StringListSize(list));
}

TEST(public_methods, index_of)
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "Lorem ipsum dolor sit amet");
    StringListAdd(&list, "consectetur adipiscing elit");
    EXPECT_EQ(2, StringListIndexOf(list, "consectetur adipiscing elit"));
    EXPECT_EQ(-1, StringListIndexOf(list, "gh"));
}

TEST(public_methods, remove)
{
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "Lorem ipsum dolor sit amet");
    StringListAdd(&list, "consectetur adipiscing elit");
    StringListRemove(list, "Lorem ipsum dolor sit amet");
    EXPECT_STREQ("consectetur adipiscing elit", list[1]);
    EXPECT_EQ(1, StringListSize(list));
}

TEST(public_methods, sort){
    char **list;
    StringListInit(&list);
    StringListAdd(&list, "lorem ipsum dolor sit amet");
    StringListAdd(&list, "consectetur adipiscing elit");
    StringListSort(list);
    EXPECT_STREQ("consectetur adipiscing elit", list[1]);
}