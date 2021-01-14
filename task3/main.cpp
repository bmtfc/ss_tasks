#include "ProjectInfo.h"

int main()
{

    //std::string path = "/Users/mac/study/politech/";
    std::string path = "/Users/mac/softserve/ss_tasks/";


    ProjectInfo A;
    A.SetListOfFilePaths(path);
    A.AnalyzeProject();
    A.PrintFilePaths();
    std::cout << A.GetNumberOfFiles() << '\n';
    std::cout << A.GetBlankLines() << '\n';


    return 0;
}
