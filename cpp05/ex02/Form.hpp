#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
        const std::string _name;
        bool              _signed;
        int               _min_sign_grade, _min_exec_grade;

        Form();

    public:
        struct GradeTooHighException : public std::logic_error {
                GradeTooHighException(const std::string &what_arg);
        };

        struct GradeTooLowException : public std::logic_error {
                GradeTooLowException(const std::string &what_arg);
        };

        struct NotSignedException : public std::logic_error {
                NotSignedException(const std::string &what_arg);
        };

        Form(
            const std::string &name, int min_sign_grade, int min_exec_grade,
            bool is_signed = false);
        Form(const Form &other);

        virtual ~Form();

        void beSigned(const Bureaucrat &bcrat);
	virtual void execute(const Bureaucrat &bcrat) const;

        const std::string &getName() const;
        bool               isSigned() const;
        int                getMinSignGrade() const;
        int                getMinExecGrade() const;

    private:
        Form &operator=(const Form &other); /* deleted */
};
std::ostream &operator<<(std::ostream &stream, const Form &form);
#endif /* FORM_HPP */
