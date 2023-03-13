#include <iostream>
#include <fstream>
#include <windows.h>//SheExecute(nullptr,"open",[Path],nullptr,nullptr,SW_SHOWNORMAL)
#include <filesystem>//filesystem::path path = filesystem::current_path();
//path.string();

std::string word(std::string result) {
    for (int i = 1; i < size(result); i++) {
        if (std::isalpha(result[i])) {
            if (result[i - 1] == 32)
                continue;
            result[i] = (char) tolower(result[i]);
        }
    }
    return result;
}

std::string (*wordPtr)(std::string str) =word;

std::string Encrypt(std::string &message, int key) {
    std::string result;
    for (int c: message) {
        if (std::isalpha(c)) {
            c = c;
            c = (((c - 'a') + key + 26) % 26) + 'a';
        }
        result += c;
    }
//    return (*wordPtr)(result);
    return result;

}

std::string Decrypt(const std::string &message, int key) {
    std::string result;
    for (int c: message) {
        if (isalpha(c)) {
            c = c;
            c = (((c - 'a') - key + 26) % 26) + 'a';
        }
        result += c;
    }

//    return (*wordPtr)(result);
    return result;
}


int main() {
    std::string str;
    std::string err;
//    std::cout << (str = Encrypt(str, 3)) << std::endl;
//    std::cout << Decrypt(str, 3);
    int key, chosen;
    std::cout << "enter 1 for encryption otherwise anything else ";
    std::cin >> chosen;
    std::string input;
    std::cout << "\nenter input file name: ";
    std::cin >> input;
    std::cout << "\nplease enter encryption key: ";
    std::cin >> key;
    std::cout << "\nenter output file name: ";
    std::string output;
    std::cin >> output;
    std::ifstream in(input + ".txt");
    std::ofstream out(output + ".txt");
    try {
        if (in) {
            std::stringstream buffer;
            buffer << in.rdbuf();
            str = buffer.str();
            in.close();
        } else throw err;
        if (out) {
            if (chosen == 1)
                out << Encrypt(str, key) << std::endl;
            else out << Decrypt(str, key) << std::endl;
            out.close();
            std::filesystem::path filePath = std::filesystem::current_path() / (output + ".txt");
            std::cout << "File path: " << filePath << std::endl;
            ShellExecute(NULL, "open", filePath.string().c_str(), NULL, NULL, SW_SHOWNORMAL);
        } else throw err;
    } catch (const char *) {
        std::cerr << "failed to create file" << std::endl;
    }
    return 0;
}
