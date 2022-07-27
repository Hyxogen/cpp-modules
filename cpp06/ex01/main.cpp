#include <cstdint>
#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data *ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
        return reinterpret_cast<Data *>(raw);
}

int main() {
        Data *data = new Data("Hello world!");
        std::cout << data->txt() << std::endl;

        uintptr_t ptr = serialize(data);
        std::cout << ptr << std::endl;

        Data *cpy = deserialize(ptr);
        std::cout << cpy->txt() << std::endl;

        delete data;
        return 0;
}
