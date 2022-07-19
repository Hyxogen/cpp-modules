#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>
#include <ctime>

#define ROBO_NAME "RobotomyRequestForm"
#define ROBO_SIGN_GRADE 72
#define ROBO_EXEC_GRADE 45
 
RobotomyRequestForm::RobotomyRequestForm() : Form(ROBO_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE), _target("unknown") { }
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form(ROBO_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE), _target(target) { }
 
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other), _target(other._target) { }
 
RobotomyRequestForm::~RobotomyRequestForm() { }
 
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		_target = other._target;	
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &bcrat) const {
	Form::execute(bcrat);
	if (rand() < RAND_MAX / 2) {
		std::cout << _target << " has been successfully robotomized" << std::endl;
	} else {
		std::cout << _target << "'s robotomization has failed" << std::endl;
	}
}

const std::string &RobotomyRequestForm::getTarget() const {
	return _target;
}

