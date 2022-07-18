#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource {
private:
	const Ice *_ice_mat;
	const Cure *_cure_mat;
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);

	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(const std::string &type);
private:
	void delete_materia();
};

#endif /* MATERIA_SOURCE_HPP */
