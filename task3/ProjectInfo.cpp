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

void ProjectInfo::SetListOfFilePaths(const std::string &path)
{
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
    for (auto &file_path : file_paths)
    {
        std::ifstream file;
        file.open(file_path);
        std::string to_analyze;
        while (!file.eof())
        {
            std::getline(file, to_analyze);
            if (is_blank_line(to_analyze))
            { blank_lines++; }
        }
        number_of_files++;
        file.close();
    }
}

int ProjectInfo::GetNumberOfFiles()
{
    return number_of_files;
}

int ProjectInfo::GetBlankLines()
{
    return blank_lines;
}