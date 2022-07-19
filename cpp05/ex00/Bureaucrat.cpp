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
