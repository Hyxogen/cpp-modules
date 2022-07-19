#include "Character.hpp"

#include "AMateria.hpp"
#include <cstdlib>
#include <stdexcept>

Character::Character() : _name("Dave") {
	init_slots();
}

Character::Character(const std::string &name) : _name(name) {
	init_slots();
}

Character::Character(const Character &other) : _name(other._name) {
	copy_slots(other);
}

Character::~Character() {
	delete_slots();
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
		delete_slots();
		copy_slots(other);
	}
	return *this;
}

const std::string &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *materia) {
	for (size_t i = 0; i < CHARACTER_INV_SLOTS; ++i) {
		if (_slots[i] == NULL) {
			_slots[i] = materia->clone();
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < CHARACTER_INV_SLOTS) {
		_slots[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < CHARACTER_INV_SLOTS && _slots[idx] != NULL) {
		_slots[idx]->use(target);
	}
}

AMateria *Character::at(std::size_t idx) {
	if (idx >= CHARACTER_INV_SLOTS) {
		throw std::out_of_range("out of bounds access in Character");
	}
	return _slots[idx];
}

void Character::init_slots() {
	for (size_t i = 0; i < CHARACTER_INV_SLOTS; ++i) {
		_slots[i] = NULL;
	}
}

void Character::delete_slots() {
	for (size_t i = 0; i < CHARACTER_INV_SLOTS; ++i) {
		delete _slots[i];
		_slots[i] = NULL;
	}
}

void Character::copy_slots(const Character &other) {
	for (size_t i = 0; i < CHARACTER_INV_SLOTS; ++i) {
		AMateria *slot = other._slots[i];
		if (slot != NULL) {
			_slots[i] = slot->clone();
		} else {
			_slots[i] = NULL;
		}
	}
}
