#include <cassert>
#include <iostream>

#include "Array.hpp"

#define ASSERT_THROW(x, type)                                                  \
 try {                                                                         \
  x;                                                                           \
  assert(0 && "Did not throw");                                                \
 } catch (const type &ex) {                                                    \
  (void) ex;                                                                   \
 } catch (const std::exception &ex) {                                          \
  assert(0 && "Threw something else");                                         \
 }

#define ASSERT_NOTHROW(x)                                                      \
 try {                                                                         \
  x;                                                                           \
 } catch (const std::exception &ex) {                                          \
  (void) ex;                                                                   \
  assert(0 && "Did throw");                                                    \
 }

#define ASSERT_EQUAL(a, b)  assert((a == b) && "Not equal")
#define ASSERT_NEQUAL(a, b) assert((a != b) && "Not equal")

void empty_array_tests() {
        Array<int> arr;
        ASSERT_EQUAL(arr.size(), 0);
}

void default_array_tests() {
        Array<int> arr(500);
        ASSERT_EQUAL(arr.size(), 500);
        for (std::size_t i = 0; i < 500; ++i) {
                ASSERT_EQUAL(arr[i], 0);
        }

        Array<std::string> strs(600);
        ASSERT_EQUAL(strs.size(), 600);
        for (std::size_t i = 0; i < 600; ++i) {
                ASSERT_EQUAL(strs[i], std::string());
        }
}

void copy_tests() {
        Array<std::string> arr(10);

        arr[7] = "General Kenobi";
        Array<std::string> cpy(arr);
        ASSERT_EQUAL(cpy.size(), 10);
        ASSERT_EQUAL(cpy[7], std::string("General Kenobi"));
        ASSERT_NEQUAL(&cpy[7], &arr[7]);
        cpy[8] = "This is where the fun begins";
        ASSERT_NEQUAL(cpy[8], arr[8]);

        arr[3] = "You are a bold one";
        Array<std::string> other;

        other = arr;
        ASSERT_EQUAL(other.size(), 10);
        ASSERT_EQUAL(other[3], std::string("You are a bold one"));
        ASSERT_EQUAL(other[7], std::string("General Kenobi"));
        ASSERT_NEQUAL(cpy[3], std::string("You are a bold one"));

        Array<int> empty;
        Array<int> not_empty(500);

        not_empty = empty;
        ASSERT_EQUAL(not_empty.size(), 0);
}

void exception_tests() {
        Array<int> empty;
        ASSERT_THROW(empty[0], std::out_of_range);

        Array<int> few(5);
        ASSERT_NOTHROW(few[4]);
        ASSERT_THROW(few[5], std::out_of_range);
}

int main() {
        empty_array_tests();
        default_array_tests();
        copy_tests();
        exception_tests();
}
