#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <vector>


int main() {
    std::filesystem::path path{"test.txt"};
    std::filesystem::path path2{"test2.txt"};
    std::filesystem::path path3{"test3.txt"};
    uint8_t key = 0xFF;
    {
        std::ofstream file(path);
        if (file.is_open()) {
            file << "Hello world! My name is Vasya. :)";
        } else {
            throw std::runtime_error("Can not open file!");
        }
        std::cout << "create file " << path << std::endl;
    }

    {
        std::ifstream file(path, std::ios::binary);
        if (file.is_open()) {
            std::string data{};
            std::stringstream  str;
            while(!file.eof())
                file >> str.rdbuf();
            data = str.str();
            std::cout << data << std::endl;
        }
    }

    {
        int const BUF_SIZE = 1024;
        std::vector<uint8_t > buffer(BUF_SIZE);
        std::ifstream file(path, std::ios::binary);
        std::ofstream file2(path2, std::ios::binary);
        file.seekg(0, std::ios::beg);
        file.read(reinterpret_cast<char*>(buffer.data()), BUF_SIZE);
        for (auto &item : buffer) {
            item = item ^ key;
        }

        file2.write(reinterpret_cast<char*>(buffer.data()), BUF_SIZE);
    }

    {
        int const BUF_SIZE = 1024;
        std::vector<uint8_t > buffer(BUF_SIZE);
        std::ifstream file2(path2, std::ios::binary);
        std::ofstream file3(path3, std::ios::binary);
        file2.seekg(0, std::ios::beg);
        file2.read(reinterpret_cast<char*>(buffer.data()), BUF_SIZE);
        for (auto &item : buffer) {
            item = item ^ key;
        }

        file3.write(reinterpret_cast<char*>(buffer.data()), BUF_SIZE);
    }

    return 0;
}