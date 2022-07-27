#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename F>
void iter(T *arr, std::size_t count, F proc) {
        while (count) {
                proc(arr[--count]);
        }
}

#endif /* ITER_HPP */
