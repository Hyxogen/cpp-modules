#include "MateriaSource.hpp"

#include <cstdlib>

MateriaSource::MateriaSource() : _ice_mat(NULL), _cure_mat(NULL) { }

MateriaSource::MateriaSource(const MateriaSource &other) :
		_ice_mat(static_cast<Ice*>(other._ice_mat->clone())),
		_cure_mat(static_cast<Cure*>(other._cure_mat->clone())) { }

MateriaSource::~MateriaSource() {
	delete_materia();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		delete_materia();
		if (other._ice_mat != NULL) {
			_ice_mat = static_cast<Ice*>(other._ice_mat->clone());
		}
		if (other._cure_mat != NULL) {
			_cure_mat= static_cast<Cure*>(other._cure_mat->clone());
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (materia->getType() == "ice" && _ice_mat == NULL) {
		_ice_mat = static_cast<Ice*>(materia->clone());
	} else if (materia->getType() == "cure" && _cure_mat == NULL) {
		_cure_mat = static_cast<Cure*>(materia->clone());
	}
	delete materia;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	if (type == "ice" && _ice_mat != NULL) {
		return _ice_mat->clone();	
	} else if (type == "cure" && _cure_mat != NULL) {
		return _cure_mat->clone();
	}
	return NULL;
}

void MateriaSource::delete_materia() {
	delete _ice_mat;
	_ice_mat = NULL;
	delete _cure_mat;
	_cure_mat = NULL;
}
