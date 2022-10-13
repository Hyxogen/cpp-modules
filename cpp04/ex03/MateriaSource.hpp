#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#ifndef MATERIASOURCE_SLOTS
# define MATERIASOURCE_SLOTS 4
#endif
#if MATERIASOURCE_SLOTS <= 0
# error "MATERIASOURCE_SLOTS must be a positive integer"
#endif

class MateriaSource : public IMateriaSource {
    private:
	AMateria *_slots[MATERIASOURCE_SLOTS];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);

        ~MateriaSource();

        MateriaSource &operator=(const MateriaSource &other);

        void      learnMateria(AMateria *materia);
        AMateria *createMateria(const std::string &type);

    private:
	void init_slots();
	void delete_slots();
	void copy_slots(const AMateria *const slots[MATERIASOURCE_SLOTS]);
};

#endif /* MATERIA_SOURCE_HPP */
