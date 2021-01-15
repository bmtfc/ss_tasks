#include "ProjectInfo.h"
#include <thread>

void AnalyzeProject(std::string path);

std::mutex g_mutex;

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

    std::thread working_thread(AnalyzeProject, path);
    working_thread.join();

    return 0;
}

void AnalyzeProject(std::string path)
{
    std::lock_guard<std::mutex> lock(g_mutex);
    ProjectAnalyzer Analyzer;
    Analyzer.SetPath(path);
    Analyzer.GenerateListOfFilePaths();
    Analyzer.AnalyzeProject();
    Analyzer.PrintInfo();
    Analyzer.CreateJson();
}