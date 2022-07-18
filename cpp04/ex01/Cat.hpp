#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
        Brain *_brain;

    public:
        Cat();
        Cat(const Cat &other);

        ~Cat();

        Cat &operator=(const Cat &other);

        void   makeSound() const;
        Brain *getBrain();
};
#endif /* CAT_HPP */
