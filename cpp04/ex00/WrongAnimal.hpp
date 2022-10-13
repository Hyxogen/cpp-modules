#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
    protected:
        std::string _type;

        WrongAnimal(const std::string &type);

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);

        virtual ~WrongAnimal();

        WrongAnimal            &operator=(const WrongAnimal &other);
        virtual void       makeSound() const;
        const std::string &getType() const;
};
#endif /* WRONG_ANIMAL_HPP */
