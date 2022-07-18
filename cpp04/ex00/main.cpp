#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
        const Animal *meta = new Animal();
        const Animal *j    = new Dog();
        const Animal *i    = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        Animal animal_copy = Animal(*meta);
        Dog    dog_copy    = Dog(*static_cast<const Dog *>(j));
        Cat    cat_copy    = Cat(*static_cast<const Cat *>(i));

        dog_copy.makeSound();
        cat_copy.makeSound();
        animal_copy.makeSound();

        dog_copy    = *static_cast<const Dog *>(j);
        cat_copy    = *static_cast<const Cat *>(i);
        animal_copy = *meta;

        dog_copy.makeSound();
        cat_copy.makeSound();
        animal_copy.makeSound();

        delete meta;
        delete j;
        delete i;
        return 0;
}
