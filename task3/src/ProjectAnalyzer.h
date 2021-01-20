#ifndef TASK3_PROJECTANALYZER_H
#define TASK3_PROJECTANALYZER_H

#include <iostream>
#include <vector>
#include <cctype>
#include <filesystem>
#include <chrono>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include "FileAnalyzer.h"


//class to analyze project
//use method SetPath() than AnalyzeProject()
//get results with CreateJson() and/or PrintInfo()
class ProjectAnalyzer
{
public:

    ProjectAnalyzer() = default;

    //set path to the project folder
    void SetPath(const std::string &t_path);

    //main function to analyze all files in project directory
    void AnalyzeProject();

    //generates .json file with results
    void CreateJson();

    //print results to console
    void PrintInfo();

    //optional : print all file paths in project directory
    void PrintFilePaths();

private:

    int number_of_files{0};
    FileData project_data;
    int elapsed_time_ms{0};
    std::string path;
    std::string project_name;
    std::vector<std::string> file_paths;

    void GenerateListOfFilePaths();

    static void ProcessFile(const std::string &file_path, FileData &curr, int &file_count, std::mutex &f_mutex);
};

#endif //TASK3_PROJECTANALYZER_H