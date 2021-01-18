#include "ProjectAnalyzer.h"

void ProjectAnalyzer::SetPath(const std::string &t_path)
{
    path = t_path;
    std::filesystem::path fake_path(path);
    project_name = fake_path.filename().string();
}

void ProjectAnalyzer::AnalyzeProject()
{
    this->GenerateListOfFilePaths();

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    boost::asio::thread_pool pool(4);
    std::mutex m;
    for (auto &file_path : file_paths)
    {
        boost::asio::post(pool, boost::bind(ProcessFile, file_path, std::ref(project_data),
                                            std::ref(number_of_files), std::ref(m)));
    }
    pool.join();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    elapsed_time_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / (1000);
}

void ProjectAnalyzer::CreateJson()
{
    boost::property_tree::ptree pt;
    pt.put("project_name", project_name);
    pt.put("full_path", path.data());
    pt.put("data.number_of_files", number_of_files);
    pt.put("data.all_lines", project_data.all_lines);
    pt.put("data.blank_lines", project_data.blank_lines);
    pt.put("data.comment_lines", project_data.comment_lines);
    pt.put("data.code_lines", project_data.code_lines);
    pt.put("data.elapsed_time_ms", elapsed_time_ms);

    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, pt);
    std::ofstream file(project_name + ".json");
    std::string data_json = ss.str();
    data_json.erase(std::remove(data_json.begin(), data_json.end(), '\\'), data_json.end());
    file << data_json;
}

void ProjectAnalyzer::PrintInfo()
{
    std::cout << "Project \"" << project_name << "\" : \n";
    std::cout << "\tpath : \"" << path << "\"\n";
    std::cout << "\tnumber of files : " << number_of_files << '\n';
    std::cout << "\tnumber of all lines : " << project_data.all_lines << '\n';
    std::cout << "\tnumber of blank lines : " << project_data.blank_lines << '\n';
    std::cout << "\tnumber of comment lines : " << project_data.comment_lines << '\n';
    std::cout << "\tnumber of code lines : " << project_data.code_lines << '\n';
    std::cout << "\telapsed time : " << elapsed_time_ms << " ms \n";
}

void ProjectAnalyzer::PrintFilePaths()
{
    for (auto &el : file_paths)
    {
        std::cout << el << '\n';
    }
}

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
            file_paths.push_back(file.path().string());
        }
    }
}

void ProjectAnalyzer::ProcessFile(const std::string &file_path, FileData &curr, int &file_count, std::mutex &f_mutex)
{
    FileData temp = FileAnalyzer::AnalyzeFile(file_path);
    f_mutex.lock();
    file_count++;
    curr += temp;
    f_mutex.unlock();
}