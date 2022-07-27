#include "test.hpp"
#include "whatever.hpp"

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
