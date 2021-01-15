//
// Created by Mac on 15.01.2021.
//

#include "ProjectInfo.h"

/* PRIVATE METHODS */
bool ProjectInfo::check_extension(const std::string &str)
{
    return str == ".h" || str == ".hpp" || str == ".c" || str == ".cpp";
}

bool ProjectInfo::is_blank_line(const std::string &str)
{
    if (str.empty())
    { return true; }
    for (auto &ch : str)
    {
        if (!(std::isspace(ch)))
        { return false; }

    }
    return true;
}

/* PUBLIC METHODS */

void ProjectInfo::GenerateListOfFilePaths()
{
    std::filesystem::path fake_path(path);
    project_name = fake_path.filename();
    for (const auto &file : std::filesystem::recursive_directory_iterator(path))
    {

        if (check_extension(file.path().extension()))
        {
            file_paths.push_back(file.path());
        }
    }
}

void ProjectInfo::PrintFilePaths()
{
    for (auto &el : file_paths)
    {
        std::cout << el << '\n';
    }
}

void ProjectInfo::AnalyzeProject()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (auto &file_path : file_paths)
    {
        std::ifstream file;
        file.open(file_path);
        std::string to_analyze;
        while (!file.eof())
        {
            std::getline(file, to_analyze);
            if (is_blank_line(to_analyze))
            {
                blank_lines++;
            } else if (is_comment_line(to_analyze))
            {
                comment_lines++;
            } else
            {
                code_lines++;
            }
        }
        number_of_files++;
        file.close();
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    elapsed_time_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

int ProjectInfo::GetNumberOfFiles()
{
    return number_of_files;
}

int ProjectInfo::GetBlankLines()
{
    return blank_lines;
}

bool ProjectInfo::is_comment_line(const std::string &str)
{
    bool check{false};
    if (str.find("//") != std::string::npos)
    {
        check = true;
    } else if (str.find("/*") != std::string::npos && str.find("*/") != std::string::npos)
    {
        check = true;
    }
    return check;
}

int ProjectInfo::GetCommentLines()
{
    return comment_lines;
}

int ProjectInfo::GetCodeLines()
{
    return code_lines;
}

int ProjectInfo::GetElapsedTime()
{
    return elapsed_time_ms;
}

void ProjectInfo::SetPath(const std::string &t_path)
{
    path = t_path;
}

void ProjectInfo::CreateJson()
{
    boost::property_tree::ptree pt;
    pt.put("project_name", project_name);
    pt.put("full_path", path);
    pt.put("data.number_of_files", number_of_files);
    pt.put("data.blank_lines", blank_lines);
    pt.put("data.comment_lines", comment_lines);
    pt.put("data.code_lines", code_lines);
    pt.put("data.elapsed_time_ms", elapsed_time_ms);

    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, pt);
    std::ofstream file(project_name + ".json");
    file << ss.str();
}

std::string ProjectInfo::GetProjectName()
{
    return project_name;
}
