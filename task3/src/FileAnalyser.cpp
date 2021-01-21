#include <fstream>
#include <regex>

#include "FileAnalyser.h"

FileData &FileData::operator+=(const FileData &r)
{
    this->all_lines += r.all_lines;
    this->blank_lines += r.blank_lines;
    this->comment_lines += r.comment_lines;
    this->code_lines += r.code_lines;
    return *this;
}


FileData FileAnalyser::AnalyzeFile(const std::string &file_path)
{
    FileData curr;
    std::fstream file;
    file.open(file_path);
    std::string to_analyze;

    std::regex rgx_blank("");
    std::regex rgx_line_comment(R"(\/\/)");
    std::regex rgx_begin_multiline_comment(R"((\/\*))");
    std::regex rgx_end_multiline_comment(R"((\*\/))");
    std::regex rgx_code_before_line_comment(R"(((\w|\s|[;,.=()])+\/\/(\w|\s|[;,.=()])*))");
    std::regex rgx_code_before_begin_multiline_comment(R"(((\w|\s|[;,.=()])+(\/\*)(\w|\s|[;,.=()])+))");
    std::regex rgx_code_after_end_multiline_comment(R"(((\w|\s|[;,.=()])+(\*\/)(\w|\s|[;,.=()])+))");

    bool MultiLineComment = false;
    while (std::getline(file, to_analyze))
    {
        if (MultiLineComment)
        {
            if (std::regex_search(to_analyze, rgx_end_multiline_comment))
            {
                curr.comment_lines++;
                if (std::regex_match(to_analyze, rgx_code_after_end_multiline_comment))
                {
                    curr.code_lines++;
                }
                MultiLineComment = false;
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
        else if (std::regex_search(to_analyze, rgx_begin_multiline_comment))
        {
            curr.comment_lines++;
            if (std::regex_match(to_analyze, rgx_code_before_begin_multiline_comment))
            {
                curr.code_lines++;
            }
            if (!std::regex_search(to_analyze, rgx_end_multiline_comment))
            {
                MultiLineComment = true;
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