#include "Util.h"

#include <cstdlib>
#include <iostream>

std::string get_line(std::istream &is, const std::string &prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(is, line);
    if (is.eof()) {
        std::exit(0); /* TODO might be better to not exit */
    }
    return line;
}

std::string truncate(std::string str, std::size_t width, char ellips) {
    if (str.length() <= width) {
        return str;
    }
    if (width == 0) {
        str = str.substr(0, 0);
    } else {
        str = str.substr(0, width - 1) + ellips;
    }
    return (str);
}
