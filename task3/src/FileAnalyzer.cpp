//
// Created by Mac on 18.01.2021.
//

#include "FileAnalyzer.h"

FileData &FileData::operator+=(const FileData &r)
{
    this->all_lines += r.all_lines;
    this->blank_lines += r.blank_lines;
    this->comment_lines += r.comment_lines;
    this->code_lines += r.code_lines;
    return *this;
}


FileData FileAnalyzer::AnalyzeFile(const std::string &file_path)
{
    FileData curr;
    std::fstream file;
    file.open(file_path);
    std::string to_analyze;

    std::regex rgx_blank("");
    std::regex rgx_line_comment(R"(\/\/)");
    std::regex rgx_code_before_line_comment(R"(((\w|\s|[;,.=()])+\/\/(\w|\s|[;,.=()])*))");
    std::regex rgx_code_before_begin_multiline_comment(R"(((\w|\s|[;,.=()])+(\/\*)(\w|\s|[;,.=()])+))");
    std::regex rgx_code_after_end_multiline_comment(R"(((\w|\s|[;,.=()])+(\*\/)(\w|\s|[;,.=()])+))");

    bool isBlockCommentLine = false;
    while (std::getline(file, to_analyze))
    {
        if (isBlockCommentLine)
        {
            if (std::regex_search(to_analyze, std::regex(R"((\*\/))"))) // end of block comment
            {
                curr.comment_lines++;
                if (std::regex_match(to_analyze, rgx_code_after_end_multiline_comment))
                {
                    curr.code_lines++;
                }
                isBlockCommentLine = false;
            }
            else
            {
                curr.comment_lines++;
            }
            continue;
        }
        if (std::regex_match(to_analyze, rgx_blank))
        {
            curr.blank_lines++;
        }
        else if (std::regex_search(to_analyze, rgx_line_comment))
        {
            curr.comment_lines++;
            if (std::regex_match(to_analyze, rgx_code_before_line_comment))
            {
                curr.code_lines++;
            }
        }
        else if (std::regex_search(to_analyze, std::regex(R"((\/\*))"))) // start of block comment
        {
            curr.comment_lines++;
            if (std::regex_match(to_analyze, rgx_code_before_begin_multiline_comment))
            {
                curr.code_lines++;
            }
            if (!std::regex_search(to_analyze, std::regex(R"((\*\/))")))
            {
                isBlockCommentLine = true;
            }
        }
        else
        {
            curr.code_lines++;
        }
        curr.all_lines++;
    }

    file.close();
    return curr;
}

