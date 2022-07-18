#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define TEST_SIZE 4

int main() {
        Animal       *dog  = new Dog();
        Animal       *cat  = new Cat();

        std::cout << dog->getType() << " " << std::endl;
        std::cout << cat->getType() << " " << std::endl;
        dog->makeSound();
        cat->makeSound();

        for (int i = 0; i < BRAIN_IDEA_SIZE; ++i) {
                static_cast<Dog *>(dog)->getBrain()->at(i) = "Squirrel!";
                static_cast<Cat *>(cat)->getBrain()->at(i) = "Zzzzzzz";
        }

        Dog    dog_copy    = Dog(*static_cast<Dog *>(dog));
        Cat    cat_copy    = Cat(*static_cast<Cat *>(cat));

        for (int i = 0; i < BRAIN_IDEA_SIZE; ++i) {
                if (dog_copy.getBrain()->at(i) != "Squirrel!") {
                        std::cout << "did not do a deep copy for dog!"
                                  << std::endl;
                }
                if (cat_copy.getBrain()->at(i) != "Zzzzzzz") {
                        std::cout << "did not do a deep copy for cat!"
                                  << std::endl;
                }
        }

        dog_copy.makeSound();
        cat_copy.makeSound();

        dog_copy    = *static_cast<Dog *>(dog);
        cat_copy    = *static_cast<Cat *>(cat);

        for (int i = 0; i < BRAIN_IDEA_SIZE; ++i) {
                if (dog_copy.getBrain()->at(i) != "Squirrel!") {
                        std::cout << "did not do a deep copy for dog!"
                                  << std::endl;
                }
                if (cat_copy.getBrain()->at(i) != "Zzzzzzz") {
                        std::cout << "did not do a deep copy for cat!"
                                  << std::endl;
                }
        }

        dog_copy.makeSound();
        cat_copy.makeSound();

        Animal *animals[TEST_SIZE];
        for (int i = 0; i < TEST_SIZE; ++i) {
                if (i < TEST_SIZE / 2) {
                        animals[i] = new Dog();
                } else {
                        animals[i] = new Cat();
                }
        }

        for (int i = 0; i < TEST_SIZE; ++i) {
                delete animals[i];
        }

        delete dog;
        delete cat;
        return 0;
}
