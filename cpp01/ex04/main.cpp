#include <fstream>
#include <iostream>
#include <string>

void read_file(std::string &out, std::ifstream &stream) {
    std::string line;
    while (std::getline(stream, line)) {
        out += line + '\n';
    }
}

void replace(
    const std::string &str1, const std::string &str2, const std::string &source,
    std::ostream &out) {
    std::string::size_type current = 0;
    std::string::size_type pos     = 0;

    while ((pos = source.find(str1, current)) != std::string::npos) {
        out << source.substr(current, pos - current);
        out << str2;
        current = pos + str1.length();
    }
    out << source.substr(current, source.length());
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << argv[0]
                  << " <filename> <string-to-replace> <string-to-replace-with>"
                  << std::endl;
        return 1;
    }
    std::ifstream infile(argv[1]);
    std::ofstream outfile(std::string(argv[1]).append(".replace").c_str());
    if (!infile || !outfile) {
        std::cerr << "failed to open files" << std::endl;
        return 1;
    }
    std::string str;
    read_file(str, infile);
    replace(argv[2], argv[3], str, outfile);
    return 0;
}
