#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>

template<typename T>
void test_swap(T &left, T &right) {
        std::cout << "swap(" << left << "(" << &left << "), " << right << "("
                  << &right << ")) ";
        swap(left, right);
        std::cout << "left " << left << "(" << &left << ") right " << right
                  << "(" << &right << ")" << std::endl;
}

template<typename T, typename F>
void test(const std::string &name, const T &left, const T &right, F proc) {
        std::cout << name << "(" << left << "(" << &left << "), " << right
                  << "(" << &right << ")) " << proc(left, right) << "("
                  << &proc(left, right) << ")" << std::endl;
}

#endif /* TEST_HPP */
