#include "ProjectInfo.h"

int main()
{

    //std::string path = "/Users/mac/study/politech/";
    std::string path = "/Users/mac/softserve/ss_tasks/task3";


    ProjectInfo A;
    A.SetListOfFilePaths(path);
    A.AnalyzeProject();
    A.PrintFilePaths();
    std::cout << A.GetNumberOfFiles() << '\n';
    std::cout << A.GetBlankLines() << '\n';
    std::cout << A.GetCommentLines() << '\n';
    std::cout << A.GetCodeLines() << '\n';
    std::cout << A.GetElapsedTime() << '\n';


    return 0;
}
