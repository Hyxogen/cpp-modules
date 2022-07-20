#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : _grade(MIN_GRADE), name("a") { }

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
    _grade(grade), name(name) {
        if (grade < MAX_GRADE) {
                throw GradeTooHighException(
                    "grade too high in bureaucrat constructor");
        } else if (grade > MIN_GRADE) {
                throw GradeTooLowException(
                    "grade too low in in bureaucrat constructor");
        }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
    _grade(other._grade), name(other.name) { }

Bureaucrat::~Bureaucrat() { }

void Bureaucrat::promote() {
        if (_grade == MAX_GRADE) {
                throw GradeTooHighException(
                    "grade would become too high in bureaucrat promote");
        }
        --_grade;
}

void Bureaucrat::demote() {
        if (_grade == MIN_GRADE) {
                throw GradeTooLowException(
                    "grade would become too low in bureaucrat promote");
        }
        ++_grade;
}

void Bureaucrat::signForm(Form &form) const {
        try {
                form.beSigned(*this);
        } catch (const Form::GradeTooLowException &ex) {
                (void) ex;
                std::cout << getName() << " couldn't sign " << form.getName()
                          << " because grade too low" << std::endl;
        }
}

void Bureaucrat::executeForm(const Form &form) const {
        try {
                form.execute(*this);
        } catch (const Form::GradeTooLowException &ex) {
                (void) ex;
                std::cout << getName() << " couldn't execute " << form.getName()
                          << " because grade too low" << std::endl;
        } catch (const Form::NotSignedException &ex) {
                std::cout << getName() << " couldn't execute " << form.getName()
                          << " because form not signed" << std::endl;
        }
        std::cout << getName() << " executed " << form.getName() << std::endl;
}

int Bureaucrat::getGrade() const {
        return _grade;
}

const std::string &Bureaucrat::getName() const {
        return name;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
        (void) other;
        return *this;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat) {
        return stream << bureaucrat.getName() << ", bureaucrat grade "
                      << bureaucrat.getGrade() << ".";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string &what_arg) :
    logic_error(what_arg) { }

Bureaucrat::GradeTooLowException::GradeTooLowException(
    const std::string &what_arg) :
    logic_error(what_arg) { }
