#include "Span.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdexcept>

Span::Span() : _contents() { }

Span::Span(unsigned int N) {
        _contents.reserve(N);
}

Span::Span(const Span &other) : _contents(other._contents) { }

Span::~Span() { }

Span &Span::operator=(const Span &other) {
        if (this != &other) {
                _contents = other._contents;
        }
        return *this;
}
void Span::addNumber(int number) {
        if (_contents.size() == _contents.capacity()) {
                throw std::length_error("Span is full");
        }
        _contents.push_back(number);
}

void Span::checkSize() const {
        if (_contents.size() <= 1) {
                throw std::length_error("Cannot determine span of size <= 1");
        }
}

std::vector<int> Span::diff() const {
        std::vector<int> sort(_contents);
        std::sort(sort.begin(), sort.end());

        std::vector<int> diff;
        std::adjacent_difference(
            _contents.begin(), _contents.end(),
            std::back_insert_iterator<std::vector<int>>(diff));
        diff.erase(diff.begin());
        return diff;
}

int Span::shortestSpan() const {
        checkSize();

        const std::vector<int> tmp = diff();
        return *std::min_element(tmp.begin(), tmp.end());
}

int Span::longestSpan() const {
        checkSize();

        const std::vector<int> tmp = diff();
        return *std::max_element(tmp.begin(), tmp.end());
}
