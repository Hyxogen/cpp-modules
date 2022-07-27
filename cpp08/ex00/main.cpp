#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include "easyfind.hpp"

template<typename T>
void test(T &container, int val) {
        std::cout << val << " ";
        typename T::iterator pos = easyfind(container, val);
        if (pos != container.end()) {
                std::cout << "found at "
                          << std::distance(container.begin(), pos);
        } else {
                std::cout << "not found";
        }
        std::cout << std::endl;
}

int main() {
        std::vector<int> vec = { 6, 0, 1, 2, 3, 4, 1, 5, 6, 7, 8 };
        std::list<int>   ints(vec.begin(), vec.end());

        for (int i = -1; i < 10; ++i) {
                test(vec, i);
                test(ints, i);
        }
}
