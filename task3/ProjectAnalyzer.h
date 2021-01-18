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
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>


#include "FileAnalyzer.h"


//@TODO : fix path ( should not end with '/' )


class ProjectAnalyzer
{
public:

    ProjectAnalyzer() = default;

    void SetPath(const std::string &t_path);

    void PrintFilePaths();

    void AnalyzeProject();

    void CreateJson();

    void PrintInfo();

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
