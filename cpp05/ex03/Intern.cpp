#include "Intern.hpp"

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

const Intern::FormEntry Intern::ENTRIES[3] = {
	{ "robotomy request", createForm<RobotomyRequestForm> },
	{ "presidential pardon", createForm<PresidentialPardonForm> },
	{ "shrubbery creation", createForm<ShrubberyCreationForm> }
};

Intern::Intern() { }

Intern::Intern(const Intern &other) { (void) other; }

Intern::~Intern() { }

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return *this;
}

Form *Intern::createForm(const std::string &type, const std::string &target) const {
	for (int i = 0; i < 3; ++i) {
		if (type == ENTRIES[i].type) {
			Form *ret = ENTRIES[i].func(target);
			std::cout << "Intern creates " << ret->getName() << std::endl;
			return ret;
		}
	}
	return NULL;
}
