#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstring>
#include <stdexcept>

template<typename T>
struct Array {
    private:
        T           *_data;
        unsigned int _size;

    public:
        Array() : _data(NULL), _size(0) { }

        Array(unsigned int n) : _data(new T[n]), _size(n) {
                while (n != 0u) {
                        _data[--n] = T();
                }
        }

        Array(const Array &other) :
            _data(new T[other._size]), _size(other._size) {
                copy_data(other);
        }

        ~Array() {
                delete[] _data;
        }

        Array &operator=(const Array &other) {
                if (this != &other) {
                        delete[] _data;
                        _data = NULL;
                        _size = 0;
                        if (other._size != 0) {
                                _data = new T[other._size];
                                _size = other._size;
                                copy_data(other);
                        }
                }
                return *this;
        }

        T &operator[](std::size_t idx) {
                if (idx >= _size) {
                        throw std::out_of_range(
                            "out of bounds access in Array::operator[]");
                }
                return _data[idx];
        }

        inline unsigned int size() const {
                return _size;
        }

    private:
        void copy_data(const Array &other) {
                for (std::size_t idx = 0; idx < _size; ++idx) {
                        _data[idx] = other._data[idx];
                }
        }
};

#endif
