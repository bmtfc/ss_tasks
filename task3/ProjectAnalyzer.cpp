//
// Created by Mac on 15.01.2021.
//

#include "ProjectAnalyzer.h"

bool check_extension(const std::string &str)
{
    return str == ".h" || str == ".hpp" || str == ".c" || str == ".cpp";
}

void ProjectAnalyzer::GenerateListOfFilePaths()
{
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
        FileData curr = FileAnalyzer::AnalyzeFile(file_path);
        // lock
        blank_lines += curr.blank_lines;
        comment_lines += curr.comment_lines;
        code_lines += curr.code_lines;
        number_of_files++;
        //unlock
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    elapsed_time_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / (1000);
}


void ProjectAnalyzer::SetPath(const std::string &t_path)
{
    path = t_path;
    std::filesystem::path fake_path(path);
    project_name = fake_path.filename();
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
