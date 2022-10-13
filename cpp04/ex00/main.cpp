#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
        const Animal      *meta       = new Animal();
        const Animal      *j          = new Dog();
        const Animal      *i          = new Cat();
        const WrongAnimal *wrong_meta = new WrongAnimal();
        const WrongAnimal *wrong_i    = new WrongCat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << wrong_i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        wrong_i->makeSound();
        wrong_meta->makeSound();

        Animal      animal_copy       = Animal(*meta);
        Dog         dog_copy          = Dog(*static_cast<const Dog *>(j));
        Cat         cat_copy          = Cat(*static_cast<const Cat *>(i));
        WrongAnimal wrong_animal_copy = WrongAnimal(*wrong_meta);
        WrongCat    wrong_cat_copy =
            WrongCat(*static_cast<const WrongCat *>(wrong_i));

        dog_copy.makeSound();
        cat_copy.makeSound();
        animal_copy.makeSound();
        wrong_cat_copy.makeSound();
        wrong_animal_copy.makeSound();

        dog_copy          = *static_cast<const Dog *>(j);
        cat_copy          = *static_cast<const Cat *>(i);
        animal_copy       = *meta;
        wrong_cat_copy    = *static_cast<const WrongCat *>(wrong_i);
        wrong_animal_copy = *wrong_meta;

        dog_copy.makeSound();
        cat_copy.makeSound();
        animal_copy.makeSound();
        wrong_cat_copy.makeSound();
        wrong_animal_copy.makeSound();

	delete wrong_meta;
        delete meta;
        delete j;
        delete i;
	delete wrong_i;
        return 0;
}
