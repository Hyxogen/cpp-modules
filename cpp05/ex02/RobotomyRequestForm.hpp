#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
 
class RobotomyRequestForm : public Form {
	std::string _target;

	RobotomyRequestForm(); /* deleted */
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
 
	~RobotomyRequestForm();
 
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(const Bureaucrat &bcrat) const;

	const std::string &getTarget() const;
};
#endif /* ROBOTOMYREQUESTFORM_HPP */

