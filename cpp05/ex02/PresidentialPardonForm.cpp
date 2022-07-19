#include "PresidentialPardonForm.hpp"

#include <iostream>

#define PRES_NAME "PresidentialPardonForm"
#define PRES_SIGN_GRADE 25
#define PRES_EXEC_GRADE 5
 
PresidentialPardonForm::PresidentialPardonForm() : Form(PRES_NAME, PRES_SIGN_GRADE, PRES_EXEC_GRADE), _target("unknown") { }
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(PRES_NAME, PRES_SIGN_GRADE, PRES_EXEC_GRADE), _target(target) { }
 
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other), _target(other._target) { }
 
PresidentialPardonForm::~PresidentialPardonForm() { }
 
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		_target = other._target;	
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &bcrat) const {
	Form::execute(bcrat);
	std::cout << _target << " has ben pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return _target;
}

