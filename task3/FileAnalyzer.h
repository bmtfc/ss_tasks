//
// Created by Mac on 18.01.2021.
//

#ifndef TASK3_FILEANALYZER_H
#define TASK3_FILEANALYZER_H

#include <string>
#include <fstream>

struct FileData{
    int blank_lines{0};
    int comment_lines{0};
    int code_lines{0};
};

class FileAnalyzer
{
public:
    static FileData AnalyzeFile(const std::string &file_path);
};


#endif //TASK3_FILEANALYZER_H
