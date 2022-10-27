#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
        std::vector<int> _contents;

        Span(); /* deleted */

    public:
        Span(unsigned int N);

        template<typename InputIt>
        Span(InputIt first, InputIt last) : _contents(first, last) { }

        Span(const Span &other);
        ~Span();

        Span &operator=(const Span &other);

        void addNumber(int number);

        template<typename InputIt>
        void addNumber(InputIt first, InputIt last) {
                for (; first != last; ++first) {
                        addNumber(*first);
                }
        }

        int shortestSpan() const;
        int longestSpan() const;

    private:
        void             checkSize() const;
        std::vector<int> diff() const;
};

#endif
