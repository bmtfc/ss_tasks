//
// Created by Mac on 18.01.2021.
//

#include "FileAnalyzer.h"


bool is_blank_line(const std::string &str)
{
    if (str.empty())
    {
        return true;
    }
    for (auto &ch : str)
    {
        if (!(std::isspace(ch)))
        {
            return false;
        }

    }
    return true;
}

bool is_comment_line(const std::string &str)
{
    bool check{false};
    if (str.find("//") != std::string::npos)
    {
        check = true;
    }
    else if (str.find("/*") != std::string::npos && str.find("*/") != std::string::npos)
    {
        check = true;
    }
    return check;
}

FileData FileAnalyzer::AnalyzeFile(const std::string &file_path)
{
    FileData curr;
    std::fstream file;
    file.open(file_path);
    std::string to_analyze;
    while (!file.eof())
    {
        std::getline(file, to_analyze);
        if (is_blank_line(to_analyze))
        {
            curr.blank_lines++;
        }
        else if (is_comment_line(to_analyze))
        {
            curr.comment_lines++;
        }
        else
        {
            curr.code_lines++;
        }
    }
    file.close();
    return curr;
}
