#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
 
class ShrubberyCreationForm : public Form {
	std::string _target;

	ShrubberyCreationForm(); /* deleted */
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
 
	~ShrubberyCreationForm();
 
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void execute(const Bureaucrat &bcrat) const;

	const std::string &getTarget() const;
};
#endif /* SHRUBBERYCREATIONFORM_HPP */

