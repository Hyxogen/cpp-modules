#include "MateriaSource.hpp"

#include <cstdlib>

MateriaSource::MateriaSource() {
	init_slots();
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	copy_slots(other._slots);
}

MateriaSource::~MateriaSource() {
        delete_slots();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
        if (this != &other) {
		delete_slots();
		copy_slots(other._slots);
        }
        return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (size_t idx = 0; idx < MATERIASOURCE_SLOTS; ++idx) {
		if (_slots[idx] == NULL) {
			_slots[idx] = materia->clone();
			break;
		}
	}
        delete materia;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (size_t idx = 0; idx < MATERIASOURCE_SLOTS; ++idx) {
		if (_slots[idx] != NULL && _slots[idx]->getType() == type) {
			return _slots[idx]->clone();
		}
	}
        return NULL;
}

void MateriaSource::init_slots() {
	for (size_t idx = 0; idx < MATERIASOURCE_SLOTS; ++idx) {
		_slots[idx] = NULL;
	}
}

void MateriaSource::delete_slots() {
	for (size_t idx = 0; idx < MATERIASOURCE_SLOTS; ++idx) {
		if (_slots[idx] != NULL) {
			delete _slots[idx];
			_slots[idx] = NULL;
		}
	}
}
void MateriaSource::copy_slots(const AMateria * const slots[MATERIASOURCE_SLOTS]) {
	for (size_t idx = 0; idx < MATERIASOURCE_SLOTS; ++idx) {
		const AMateria *slot = slots[idx];
                if (slot != NULL) {
                        _slots[idx] = slot->clone();
                } else {
                        _slots[idx] = NULL;
                }
	}
}
