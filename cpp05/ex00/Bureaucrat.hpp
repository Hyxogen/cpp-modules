#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

#ifndef MAX_GRADE
# define MAX_GRADE 1
#endif

#ifndef MIN_GRADE
# define MIN_GRADE 150
#endif
 
class Bureaucrat {
private:
	int _grade;
public:
	struct GradeTooHighException : public std::logic_error {
		GradeTooHighException(const std::string &what_arg);
	};

	struct GradeTooLowException : public std::logic_error {
		GradeTooLowException(const std::string &what_arg);
	};

	const std::string name;

	Bureaucrat();
	Bureaucrat(const std::string &name, int grade = MIN_GRADE);
	Bureaucrat(const Bureaucrat &other);
 
	~Bureaucrat();

	void promote();
	void demote();

	int getGrade() const;
	const std::string &getName() const;
private:
	Bureaucrat &operator=(const Bureaucrat &other); /* deleted */
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
#endif /* BUREAUCRAT_HPP */

