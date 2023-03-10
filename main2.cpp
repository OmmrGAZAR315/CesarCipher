#include <iostream>
#include <windows.h>
#include <filesystem>
#include <fstream>

int main() {
    std::string str = "outPutFILE.txt";
    std::ofstream outputfile(str);
    std::filesystem::path filePosition = std::filesystem::current_path() / "outPutFILE.txt";
    ShellExecute(nullptr, "open", filePosition.string().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}