#include <cstdlib>
#include <iostream>

#include "iter.hpp"

void square_and_print(int val) {
        std::cout << val * val << std::endl;
}

int main() {
        const int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int      *other = new int[100];

        iter(arr, 10, square_and_print);

        for (int i = 0; i < 100; ++i) {
                other[i] = rand() % 500;
        }
        iter(other, 100, square_and_print);

        delete[] other;
        return 0;
}
