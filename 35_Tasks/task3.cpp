#include <iostream>
#include <filesystem>
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

auto recursiveGetFileNameByExtension = [](fs::path path, const std::string extension)
{
    std::vector<fs::path> output;
    for(const auto& p : fs::recursive_directory_iterator(path))
        if(p.path().extension().compare(extension))
            output.push_back(p.path());

    return output;
};

int main()
{
    std::string extension(".run");
    fs::path p("/home/user/");

    auto arr = recursiveGetFileNameByExtension(p, extension);

    for (const auto& el : arr)
        std::cout << el << std::endl;
}