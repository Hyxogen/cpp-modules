#include <algorithm>
#include <cassert>
#include <list>
#include <stdexcept>
#include <vector>

#include "Span.hpp"

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

void add_number_tests() {
        {
                Span span(0);

                ASSERT_THROW(span.addNumber(42), std::length_error);
                ASSERT_THROW(span.addNumber(11), std::length_error);
        }
        {
                Span span(1);

                ASSERT_NOTHROW(span.addNumber(42));
                ASSERT_THROW(span.addNumber(11), std::length_error);
        }
        {
                Span span(10);

                for (int i = 0; i < 10; ++i) {
                        ASSERT_NOTHROW(span.addNumber(i));
                }
                ASSERT_THROW(span.addNumber(342), std::length_error);
                ASSERT_THROW(span.addNumber(5), std::length_error);
        }
        {
                Span span(100000);

                for (int i = 0; i < 100000; ++i) {
                        ASSERT_NOTHROW(span.addNumber(i));
                }
                ASSERT_THROW(span.addNumber(342), std::length_error);
                ASSERT_THROW(span.addNumber(5), std::length_error);
        }
        {
                const std::vector<int> vec(10, 42);
                Span                   span(10);

                ASSERT_NOTHROW(span.addNumber(vec.begin(), vec.end()));
        }
        {
                const std::vector<int> vec(10, 42);
                Span                   span(5);

                ASSERT_THROW(
                    span.addNumber(vec.begin(), vec.end()), std::length_error);
        }
        {
                const std::vector<int> vec(9, 42);
                Span                   span(10);

                ASSERT_NOTHROW(span.addNumber(5));
                ASSERT_NOTHROW(span.addNumber(vec.begin(), vec.end()));
        }
}

void constructor_tests() {
        {
                std::vector<int> input(100000);
                std::generate(input.begin(), input.end(), std::rand);

                Span span(input.begin(), input.end());
                ASSERT_THROW(span.addNumber(342), std::length_error);
                ASSERT_THROW(span.addNumber(5), std::length_error);
        }
        {
                std::list<int> input(100000);
                std::generate(input.begin(), input.end(), std::rand);

                Span span(input.begin(), input.end());
                ASSERT_THROW(span.addNumber(342), std::length_error);
                ASSERT_THROW(span.addNumber(5), std::length_error);
        }
}

void shortest_span_tests() {
        {
                Span span(0);
                ASSERT_THROW(span.shortestSpan(), std::length_error);
        }
        {
                Span span(1);
                ASSERT_THROW(span.shortestSpan(), std::length_error);
        }
        {
                Span span(10);

                ASSERT_THROW(span.shortestSpan(), std::length_error);
                span.addNumber(42);
                ASSERT_THROW(span.shortestSpan(), std::length_error);
                span.addNumber(42);

                ASSERT_EQUAL(span.shortestSpan(), 0);
        }
        {
                const std::vector<int> vec;

                Span span(10);
                span.addNumber(vec.begin(), vec.end());
                ASSERT_THROW(span.shortestSpan(), std::length_error);
        }
        {
                Span span(10);

                span.addNumber(1);
                span.addNumber(50);
                span.addNumber(52);

                ASSERT_EQUAL(span.shortestSpan(), 2);
        }
        {
                std::vector<int> vec;

                vec.push_back(1);
                vec.push_back(50);
                vec.push_back(52);

                Span span(10);

                span.addNumber(vec.begin(), vec.end());
                ASSERT_EQUAL(span.shortestSpan(), 2);
        }
        {
                Span span(10);

                span.addNumber(1);
                span.addNumber(50);
                span.addNumber(52);
                span.addNumber(54);

                ASSERT_EQUAL(span.shortestSpan(), 2);
        }
        {
                Span span(100000);

                for (int i = 0; i < 100000; ++i) {
                        if (i > 53000 && i < 53010) {
                                span.addNumber(i);
                        } else {
                                span.addNumber(i);
                                ++i;
                        }
                }

                ASSERT_EQUAL(span.shortestSpan(), 1);
        }
}

void longest_span_tests() {
        {
                Span span(0);
                ASSERT_THROW(span.longestSpan(), std::length_error);
        }
        {
                Span span(1);
                ASSERT_THROW(span.longestSpan(), std::length_error);
        }
        {
                Span span(10);

                ASSERT_THROW(span.longestSpan(), std::length_error);
                span.addNumber(42);
                ASSERT_THROW(span.longestSpan(), std::length_error);
                span.addNumber(42);

                ASSERT_EQUAL(span.longestSpan(), 0);
        }
        {
                const std::vector<int> vec;

                Span span(10);
                ASSERT_THROW(span.longestSpan(), std::length_error);
        }
        {
                Span span(10);

                span.addNumber(1);
                span.addNumber(50);
                span.addNumber(52);

                ASSERT_EQUAL(span.longestSpan(), 49);
        }
        {
                std::vector<int> vec;
                vec.push_back(1);
                vec.push_back(50);
                vec.push_back(52);

                Span span(10);

                span.addNumber(vec.begin(), vec.end());
                ASSERT_EQUAL(span.longestSpan(), 49);
        }
        {
                Span span(10);

                span.addNumber(50);
                span.addNumber(60);
                span.addNumber(70);
                span.addNumber(82);

                ASSERT_EQUAL(span.longestSpan(), 12);
        }
        {
                Span span(100000);

                for (int i = 0; i < 100000; ++i) {
                        if (i > 53000 && i < 53010) {
                                span.addNumber(i);
                        } else {
                                span.addNumber(i);
                                ++i;
                        }
                }

                ASSERT_EQUAL(span.longestSpan(), 2);
        }
}

int main() {
        add_number_tests();
        constructor_tests();
        shortest_span_tests();
        longest_span_tests();
}
