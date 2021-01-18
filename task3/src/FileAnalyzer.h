#ifndef TASK3_FILEANALYZER_H
#define TASK3_FILEANALYZER_H

#include <string>
#include <fstream>
#include <regex>

//struct to contain data about files
struct FileData
{
    int all_lines{0};
    int blank_lines{0};
    int comment_lines{0};
    int code_lines{0};

    FileData &operator+=(const FileData &r);
};
//class to analyze file
class FileAnalyzer
{
public:
    static FileData AnalyzeFile(const std::string &file_path);
};


#endif //TASK3_FILEANALYZER_H
