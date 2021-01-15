//
// Created by Mac on 15.01.2021.
//

#ifndef TASK3_PROJECTINFO_H
#define TASK3_PROJECTINFO_H

#include <iostream>

#include <filesystem>
#include <vector>

#include <fstream>
#include <string>
#include <cctype>

#include <chrono>

//@TODO : multiline comments
//@TODO : elapsed time
//@TODO : .json for results
//@TODO : multithreading


class ProjectInfo
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
    std::vector<std::string> file_paths;
private /*methods*/ :
    static bool check_extension(const std::string &str);

    static bool is_blank_line(const std::string &str);

    static bool is_comment_line(const std::string &str);

public:

    ProjectInfo() = default;

    void SetListOfFilePaths(const std::string &path);

    void PrintFilePaths();

    void AnalyzeProject();

    int GetNumberOfFiles();

    int GetBlankLines();

    int GetCommentLines();

    int GetCodeLines();

    int GetElapsedTime();

};


#endif //TASK3_PROJECTINFO_H
