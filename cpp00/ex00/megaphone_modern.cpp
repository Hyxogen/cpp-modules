#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
        std::vector<std::string> words(argv + 1, argv + argc);

        if (argc == 1)
                words.push_back("* LOUD AND UNBEARABLE FEEDBACK NOISE *");

        for (auto &w : words) {
                std::transform(
                    w.cbegin(), w.cend(), w.begin(), [](unsigned char c) {
                            return std::toupper(c);
                    });
                std::cout << w;
        }
        std::cout << std::endl;
        return 0;
}
