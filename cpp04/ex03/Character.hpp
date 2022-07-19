#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#ifndef CHARACTER_INV_SLOTS
# define CHARACTER_INV_SLOTS 4
#endif
#if CHARACTER_INV_SLOTS <= 0
# error "CHARACTER_INV_SLOTS must be a positive integer"
#endif

class Character : public ICharacter {
        std::string _name;
        AMateria   *_slots[CHARACTER_INV_SLOTS];

        Character();

    public:
        Character(const std::string &name);
        Character(const Character &other);

        ~Character();

        Character &operator=(const Character &other);

        const std::string &getName() const;
        void               equip(AMateria *materia);
        void               unequip(int idx);
        void               use(int idx, ICharacter &target);
        AMateria          *at(std::size_t idx);

    private:
        void init_slots();
        void delete_slots();
        void copy_slots(const Character &other);
};

#endif /* CHARACTER_HPP */
