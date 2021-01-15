#include "ProjectInfo.h"

int main()
{
    std::string path = "/Users/mac/study/politech";
    //std::string path = "/Users/mac/softserve/ss_tasks";


    ProjectInfo A;
    A.SetPath(path);
    A.GenerateListOfFilePaths();
    A.AnalyzeProject();
    A.PrintFilePaths();
    std::cout << A.GetProjectName() << " : \n";
    std::cout << A.GetNumberOfFiles() << '\n';
    std::cout << A.GetBlankLines() << '\n';
    std::cout << A.GetCommentLines() << '\n';
    std::cout << A.GetCodeLines() << '\n';
    std::cout << A.GetElapsedTime() << '\n';
    A.CreateJson();


    return 0;
}
