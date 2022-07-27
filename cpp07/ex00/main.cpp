#include <iostream>
#include <string>

#include "whatever.hpp"

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

int main() {
        int i = 21;
        int j = 42;

        test_swap(i, i);
        test_swap(i, j);
        test_swap(i, j);
        test_swap(j, i);

        test("min", 21, 42, min<int>);
        test("min", 42, 21, min<int>);
        test("min", 42, 42, min<int>);

        test("max", 21, 42, max<int>);
        test("max", 42, 21, max<int>);
        test("max", 42, 42, max<int>);
}
