#include "Form.hpp"

#include <iostream>

Form::Form() :
    _name("unknown form"), _signed(false), _min_sign_grade(MIN_GRADE),
    _min_exec_grade(MIN_GRADE) { }

Form::Form(
    const std::string &name, int min_sign_grade, int min_exec_grade,
    bool is_signed) :
    _name(name),
    _signed(is_signed), _min_sign_grade(min_sign_grade),
    _min_exec_grade(min_exec_grade) {
        if (min_sign_grade > MIN_GRADE) {
                throw GradeTooLowException(
                    "sign_grade too low in form constructor");
        } else if (min_sign_grade < MAX_GRADE) {
                throw GradeTooHighException(
                    "sign_grade too high in form constructor");
        }
        if (min_exec_grade > MIN_GRADE) {
                throw GradeTooLowException(
                    "exec_grade too low in form constructor");
        } else if (min_exec_grade < MAX_GRADE) {
                throw GradeTooHighException(
                    "exec_grade too high in form constructor");
        }
}

Form::Form(const Form &other) :
    _name(other._name), _signed(other._signed),
    _min_sign_grade(other._min_sign_grade),
    _min_exec_grade(other._min_exec_grade) { }

Form::~Form() { }

Form &Form::operator=(const Form &other) {
        (void) other;
        return *this;
}

void Form::beSigned(const Bureaucrat &bcrat) {
        if (bcrat.getGrade() > _min_sign_grade) {
                throw GradeTooLowException("grade too low in form beSigned");
        }
        _signed = true;
}

void Form::execute(const Bureaucrat &bcrat) const {
	if (bcrat.getGrade() > _min_exec_grade) {
		throw GradeTooLowException("grade too low in form execute");
	}
	if (_signed == false) {
		throw NotSignedException("form not signed in form execute");
	}
}

const std::string &Form::getName() const {
        return _name;
}

bool Form::isSigned() const {
        return _signed;
}

int Form::getMinSignGrade() const {
        return _min_sign_grade;
}

int Form::getMinExecGrade() const {
        return _min_exec_grade;
}

std::ostream &operator<<(std::ostream &stream, const Form &form) {
        return stream << "form " << form.getName() << ", min sign grade "
                      << form.getMinSignGrade() << ", min exec grade "
                      << form.getMinExecGrade() << ".";
}

Form::GradeTooHighException::GradeTooHighException(
    const std::string &what_arg) :
    logic_error(what_arg) { }

Form::GradeTooLowException::GradeTooLowException(const std::string &what_arg) :
    logic_error(what_arg) { }

Form::NotSignedException::NotSignedException(const std::string &what_arg) : logic_error(what_arg) { }
