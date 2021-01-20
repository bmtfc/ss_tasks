#include "gtest/gtest.h"
#include "/Users/mac/softserve/ss_tasks/task3/src/FileAnalyser.h"
#include "/Users/mac/softserve/ss_tasks/task3/src/ProjectAnalyser.h"

TEST(file_analyzer, oper_add)
{
    FileData x{1, 2, 3, 4};
    FileData y{3, 3, 3, 3};
    x += y;
    ASSERT_EQ(4, x.all_lines);
    ASSERT_EQ(5, x.blank_lines);
    ASSERT_EQ(6, x.comment_lines);
    ASSERT_EQ(7, x.code_lines);
}

TEST(file_analyzer, analyze_file)
{
    const auto temp = FileAnalyser::AnalyzeFile("/Users/mac/softserve/ss_tasks/task3/tests/FOR_TESTING.h");
    ASSERT_EQ(7, temp.code_lines);
    ASSERT_EQ(6, temp.comment_lines);
    ASSERT_EQ(4, temp.blank_lines);
    ASSERT_EQ(11, temp.all_lines);
}

TEST(project_analyzer, analyze)
{
    ProjectAnalyzer A;
    A.SetPath("/Users/mac/softserve/ss_tasks/task3/tests");
    A.AnalyzeProject();
    ASSERT_NO_THROW();
}


