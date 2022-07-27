#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
        const int type = rand() % 3;
        std::cout << "created ";
        Base *ptr = NULL;
        if (type == 0) {
                ptr = new A();
                std::cout << "A";
        } else if (type == 1) {
                ptr = new B();
                std::cout << "B";
        } else {
                ptr = new C();
                std::cout << "C";
        }
        std::cout << std::endl;
        return ptr;
}

void identify(Base *ptr) {
        std::cout << ptr << " is of type: ";
        if (dynamic_cast<A *>(ptr) != NULL) {
                std::cout << "A";
        } else if (dynamic_cast<B *>(ptr) != NULL) {
                std::cout << "B";
        } else if (dynamic_cast<C *>(ptr) != NULL) {
                std::cout << "C";
        } else {
                std::cout << "unknown";
        }
        std::cout << std::endl;
}

void identify(Base &ptr) {
        identify(&ptr);
}

int main() {
        for (int i = 0; i < 15; ++i) {
                Base *ptr = generate();
                identify(ptr);
                identify(*ptr);
                std::cout << std::endl;
                delete ptr;
        }
}
