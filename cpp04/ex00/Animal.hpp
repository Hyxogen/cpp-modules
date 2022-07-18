#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
    protected:
        std::string _type;

        Animal(const std::string &type);

    public:
        Animal();
        Animal(const Animal &other);

        virtual ~Animal();

        Animal            &operator=(const Animal &other);
        virtual void       makeSound() const;
        const std::string &getType() const;
};
#endif /* ANIMAL_HPP */
