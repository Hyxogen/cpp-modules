#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &left, T &right) {
        T tmp(left);
        left  = right;
        right = tmp;
}

template<typename T>
const T &min(const T &left, const T &right) {
        if (right <= left) {
                return right;
        }
        return left;
}

template<typename T>
const T &max(const T &left, const T &right) {
        if (right >= left) {
                return right;
        }
        return left;
}

#endif /* WHATEVER_HPP */
