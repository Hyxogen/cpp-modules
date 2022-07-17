#ifndef UTIL_H
#define UTIL_H

#include <string>

std::string get_line(std::istream &is, const std::string &prompt);

std::string truncate(std::string str, std::size_t width, char ellips);

#endif
