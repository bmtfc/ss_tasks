#include "ProjectAnalyzer.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "You haven't enter the path to project directory\n";
        return 1;
    }
    if (argc > 2)
    {
        std::cout << "You have entered too mane arguments\n";
        return 2;
    }

    std::string project_path(argv[1]);
    //fixing entered path
    if (*(project_path.end() - 1) == '/')
    {
        project_path.erase(project_path.end() - 1);
    }
    ProjectAnalyzer Analyzer;
    Analyzer.SetPath(project_path);
    Analyzer.AnalyzeProject();
    Analyzer.PrintInfo();
    Analyzer.CreateJson();
    return 0;
}