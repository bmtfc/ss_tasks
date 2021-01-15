#include "ProjectInfo.h"

int main()
{
    std::string path = "/Users/mac/softserve/ss_tasks";


    ProjectInfo SSTasks;
    SSTasks.SetPath(path);
    SSTasks.GenerateListOfFilePaths();
    SSTasks.AnalyzeProject();
    SSTasks.PrintFilePaths();
    SSTasks.PrintInfo();
    SSTasks.CreateJson();


    return 0;
}
