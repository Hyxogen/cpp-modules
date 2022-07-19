#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>

void character_tests() {
	std::cout << "----Character tests----" << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");

	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << "Normal usage" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "Empty character" << std::endl;
	Character c("void");
	c.use(0, *bob);
	c.use(1, *bob);
	c.use(2, *bob);
	c.use(3, *bob);

	std::cout << "Only one materia (cure)" << std::endl;
	c.equip(tmp);
	c.use(0, *bob);
	c.use(1, *bob);
	c.use(2, *bob);
	c.use(3, *bob);

	std::cout << "Two materia (ice)" << std::endl;
	delete tmp;
	tmp = src->createMateria("ice");
	c.equip(tmp);
	c.use(0, *bob);
	c.use(1, *bob);
	c.use(2, *bob);
	c.use(3, *bob);

	std::cout << "Third materia (ice)" << std::endl;
	c.equip(tmp);
	c.use(0, *bob);
	c.use(1, *bob);
	c.use(2, *bob);
	c.use(3, *bob);

	std::cout << "Fourth materia (ice)" << std::endl;
	c.equip(tmp);
	c.use(0, *bob);
	c.use(1, *bob);
	c.use(2, *bob);
	c.use(3, *bob);

	std::cout << "Fifth materia (ice)" << std::endl;
	c.equip(tmp);
	c.use(0, *bob);
	c.use(1, *bob);
	c.use(2, *bob);
	c.use(3, *bob);

	for (int i = 0; i < 4; i++) {
		std::cout << "Unequip slot " << i << std::endl;
		delete c.at(i);
		c.unequip(i);
		c.use(0, *bob);
		c.use(1, *bob);
		c.use(2, *bob);
		c.use(3, *bob);
	}

	Character char1("steve");
	Character char2("john");

	char1 = char2;
	if (char1.getName() != "john" || char2.getName() != "john") {
		std::cout << "Failed to copy name in copy assignment!" << std::endl;
	}

	char1 = *static_cast<Character*>(me);
	std::cout << "steve should be able to cast both ice and cure on bob" << std::endl;
	char1.use(0, *bob);
	char1.use(1, *bob);
	char1.use(3, *bob);
	char1.use(4, *bob);

	if (char1.at(0) == static_cast<Character*>(me)->at(0)) {
		std::cout << "Did not do a deep copy!" << std::endl;
	}

	delete tmp;
	delete bob;
	delete me;
	delete src;
}

void materia_tests() {
	std::cout << "----Materia tests----" << std::endl;

	Character c("a poor fool");
	Ice ice;
	Ice ice_cpy;

	std::cout << "Type should be ice: " << ice.getType() << std::endl;
	std::cout << "Use ice" << std::endl;

	ice.use(c);

	ice_cpy = ice;
	std::cout << "Type should be ice: " << ice_cpy.getType() << std::endl;
	std::cout << "Use ice_cpy" << std::endl;
	ice_cpy.use(c);

	AMateria *copy = ice.clone();
	if (dynamic_cast<Ice*>(copy) == NULL) {
		std::cout << "If you see this message, a test failed" << std::endl;
	}
	std::cout << "Type should be ice: " << copy->getType() << std::endl;
	copy->use(c);

	delete copy;

	Cure cure;
	Cure cure_cpy;

	std::cout << "Type should be cure: " << cure.getType() << std::endl;
	std::cout << "Use cure" << std::endl;

	cure.use(c);

	cure_cpy = cure;
	std::cout << "Type should be cure: " << cure_cpy.getType() << std::endl;
	std::cout << "Use cure_cpy" << std::endl;
	cure_cpy.use(c);

	copy = cure.clone();
	if (dynamic_cast<Cure*>(copy) == NULL) {
		std::cout << "If you see this message, a test failed" << std::endl;
	}
	std::cout << "Type should be cure: " << copy->getType() << std::endl;
	copy->use(c);

	delete copy;
}

void materiasource_tests() {
	std::cout << "----Materia Source tests----" << std::endl;

	Character subject("test subject");
	MateriaSource empty;
	MateriaSource src;

	AMateria *tmp = src.createMateria("ice");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	tmp = src.createMateria("cure");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	tmp = src.createMateria("ice cream");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}
	
	src.learnMateria(new Ice());

	tmp = src.createMateria("ice");
	if (tmp == NULL) {
		std::cout << "Get null when expecting a pointer at: " << __LINE__ << std::endl;
	} else if (dynamic_cast<Ice*>(tmp) == NULL) {
		std::cout << "Expected an object of type Ice at: " << __LINE__ << std::endl;
	} else {
		std::cout << "use ice" << std::endl;
		tmp->use(subject);
	}

	delete tmp;
	tmp = src.createMateria("cure");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	tmp = src.createMateria("ice cream");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	src = empty;
	tmp = src.createMateria("ice");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	tmp = src.createMateria("cure");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	tmp = src.createMateria("ice cream");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	src.learnMateria(new Cure());

	tmp = src.createMateria("cure");
	if (tmp == NULL) {
		std::cout << "Get null when expecting a pointer at: " << __LINE__ << std::endl;
	} else if (dynamic_cast<Cure*>(tmp) == NULL) {
		std::cout << "Expected an object of type Ice at: " << __LINE__ << std::endl;
	} else {
		std::cout << "use cure" << std::endl;
		tmp->use(subject);
	}

	delete tmp;
	tmp = src.createMateria("ice");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}

	tmp = src.createMateria("ice cream");
	if (tmp != NULL) {
		std::cout << "Got a pointer when expecting null at: "  << __LINE__ << std::endl;
	}
}

int main() {
	character_tests();
	materia_tests();
	materiasource_tests();
	return 0;
}
