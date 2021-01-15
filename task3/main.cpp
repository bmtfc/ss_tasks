#include "ProjectInfo.h"
#include <thread>

void AnalyzeProject(const std::string &path);

int main()
{
    std::cout << "Enter path to the project (without '\' in the end of path )\n";
    std::cout << "Example : path \"/Users/mac/softserve/ss_tasks\", so project name : \"ss_tasks\"\n";
    std::string path;
    std::cin >> path;
    if (path == "test")
    {
        path = "/Users/mac/softserve/ss_tasks";
    }

    AnalyzeProject(path);

    return 0;
}

void AnalyzeProject(const std::string &path)
{
    ProjectAnalyzer Analyzer;
    Analyzer.SetPath(path);
    Analyzer.GenerateListOfFilePaths();
    Analyzer.PrintFilePaths();
    Analyzer.AnalyzeProject();
    Analyzer.PrintInfo();
    Analyzer.CreateJson();
}