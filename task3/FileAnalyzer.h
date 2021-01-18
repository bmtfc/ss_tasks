//
// Created by Mac on 18.01.2021.
//

#ifndef TASK3_FILEANALYZER_H
#define TASK3_FILEANALYZER_H

#include <string>
#include <fstream>
#include <regex>

//@TODO : multiline comments
//TODO : REGEX BLYAT

struct FileData
{
    int all_lines{0};
    int blank_lines{0};
    int comment_lines{0};
    int code_lines{0};

    FileData &operator+=(const FileData &r);

};

class FileAnalyzer
{
public:
    static FileData AnalyzeFile(const std::string &file_path);
};


#endif //TASK3_FILEANALYZER_H
