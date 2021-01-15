//
// Created by Mac on 15.01.2021.
//

#include "ProjectInfo.h"

/* PRIVATE METHODS */
bool check_extension(const std::string &str)
{
    return str == ".h" || str == ".hpp" || str == ".c" || str == ".cpp";
}

bool is_blank_line(const std::string &str)
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

bool is_comment_line(const std::string &str)
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

/* PUBLIC METHODS */

void ProjectAnalyzer::GenerateListOfFilePaths()
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

void ProjectAnalyzer::PrintFilePaths()
{
    for (auto &el : file_paths)
    {
        std::cout << el << '\n';
    }
}

void ProjectAnalyzer::AnalyzeProject()
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

int ProjectAnalyzer::GetNumberOfFiles()
{
    return number_of_files;
}

int ProjectAnalyzer::GetBlankLines()
{
    return blank_lines;
}


int ProjectAnalyzer::GetCommentLines()
{
    return comment_lines;
}

int ProjectAnalyzer::GetCodeLines()
{
    return code_lines;
}

int ProjectAnalyzer::GetElapsedTime()
{
    return elapsed_time_ms;
}

void ProjectAnalyzer::SetPath(const std::string &t_path)
{
    path = t_path;
}

void ProjectAnalyzer::CreateJson()
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

std::string ProjectAnalyzer::GetProjectName()
{
    return project_name;
}

void ProjectAnalyzer::PrintInfo()
{
    std::cout << "Project \"" << project_name << "\" : \n";
    std::cout << "\tpath : \"" << path << "\"\n";
    std::cout << "\tnumber of files : " << number_of_files << '\n';
    std::cout << "\tnumber of blank lines : " << blank_lines << '\n';
    std::cout << "\tnumber of comment lines : " << comment_lines << '\n';
    std::cout << "\tnumber of code lines : " << code_lines << '\n';
    std::cout << "\telapsed time : " << elapsed_time_ms << " ms \n";
}
