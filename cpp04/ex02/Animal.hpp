#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
    protected:
        const std::string type;

        Animal(const std::string &type);

    public:
        Animal();
        Animal(const Animal &other);

        virtual ~Animal();

        virtual void       makeSound() const = 0;
        const std::string &getType() const;

    private:
        Animal &operator=(const Animal &other);
};
#endif /* ANIMAL_HPP */
