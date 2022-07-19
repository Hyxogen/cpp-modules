#include "ShrubberyCreationForm.hpp"

#include <fstream>

#define SHRUB_NAME "ShrubberyCreationForm"
#define SHRUB_SIGN_GRADE 145
#define SHRUB_EXEC_GRADE 137
 
ShrubberyCreationForm::ShrubberyCreationForm() : Form(SHRUB_NAME, SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE), _target("unknown") { }
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form(SHRUB_NAME, SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE), _target(target) { }
 
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other), _target(other._target) { }
 
ShrubberyCreationForm::~ShrubberyCreationForm() { }
 
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		_target = other._target;	
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bcrat) const {
	Form::execute(bcrat);
	std::ofstream file(std::string(_target).append("_shrubbery").c_str());
	if (!file) {
		throw std::ios_base::failure("failed to open file in ShrubberyCreationForm execute");	
	}
	file << "/" << std::endl
		<< "├── bin" << std::endl
		<< "├── boot" << std::endl
		<< "│   └── grub" << std::endl
		<< "│       ├── fonts" << std::endl
		<< "│       ├── themes" << std::endl
		<< "│       └── locale" << std::endl
		<< "├── dev" << std::endl
		<< "│   ├── block" << std::endl
		<< "│   ├── bsg" << std::endl
		<< "│   ├── bus" << std::endl
		<< "│   │   └── usb" << std::endl
		<< "│   ├── char" << std::endl
		<< "│   ├── cpu" << std::endl
		<< "│   └── disk" << std::endl
		<< "├── home" << std::endl 
		<< "├── mnt" << std::endl
		<< "├── opt" << std::endl 
		<< "└── sys" << std::endl
		<< "    ├── block" << std::endl
		<< "    ├── bus" << std::endl
		<< "    └── devices" << std::endl
		<< "        ├── cpu" << std::endl
		<< "        └── system" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return _target;
}

