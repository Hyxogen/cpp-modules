#include <cctype>
#include <iostream>

static void PrintArgs(int argc, char **argv) {
    for (int index = 1; index < argc; index++) {
        std::string word(argv[index]);
        for (std::string::iterator it = word.begin(); it != word.end(); ++it) {
            std::cout << static_cast<char>(
                std::toupper(static_cast<char>(*it)));
        }
    }
}

static void PrintNoArgs() {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

int main(int argc, char **argv) {
    if (argc == 1)
        PrintNoArgs();
    else
        PrintArgs(argc, argv);
    std::cout << std::endl;
    return 0;
}
