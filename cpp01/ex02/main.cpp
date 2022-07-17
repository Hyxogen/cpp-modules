#include <iostream>
#include <string>

int main() {
    const std::string  str = "HI THIS IS BRAIN";
    const std::string *ptr = &str;
    const std::string &ref = str;

    std::cout << &str << std::endl;
    std::cout << &ptr << std::endl;
    std::cout << &ref << std::endl;

    std::cout << str << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;
    return 0;
}
