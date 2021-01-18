#include "gtest/gtest.h"
#include "/Users/mac/softserve/ss_tasks/task3/src/FileAnalyzer.h"
#include "/Users/mac/softserve/ss_tasks/task3/src/ProjectAnalyzer.h"

TEST(file_analyzer, oper_add)
{
    FileData x{1, 2, 3, 4};
    FileData y{3, 3, 3, 3};
    x += y;
    ASSERT_EQ(4, x.all_lines);
}

TEST(file_analyzer, analyze_file)
{
    const auto temp = FileAnalyzer::AnalyzeFile("/Users/mac/softserve/ss_tasks/task3/tests/FOR_TESTING.h");
    ASSERT_EQ(7, temp.code_lines);
}

TEST(project_analyzer, analyze)
{
    ProjectAnalyzer A;
    A.SetPath("/Users/mac/softserve/ss_tasks/task3/tests");
    A.AnalyzeProject();
    ASSERT_NO_THROW();
}


