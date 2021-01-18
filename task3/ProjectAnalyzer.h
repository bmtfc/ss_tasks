//
// Created by Mac on 15.01.2021.
//

#ifndef TASK3_PROJECTANALYZER_H
#define TASK3_PROJECTANALYZER_H

#include <iostream>

#include <filesystem>
#include <vector>

#include <cctype>
#include <chrono>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>

#include "FileAnalyzer.h"


//@TODO : fix path ( should not end with '/' )
//@TODO : multiline comments
//@TODO : multithreading


class ProjectAnalyzer
{
private:
    struct
    {
        int number_of_files{0};
        int blank_lines{0};
        int comment_lines{0};
        int code_lines{0};
        int elapsed_time_ms{0};
    };
    std::string path;
    std::string project_name;
    std::vector<std::string> file_paths;

public:

    ProjectAnalyzer() = default;

    void SetPath(const std::string &t_path);

    void GenerateListOfFilePaths();

    void PrintFilePaths();

    void AnalyzeProject();

    void CreateJson();

    void PrintInfo();

};


#endif //TASK3_PROJECTANALYZER_H
