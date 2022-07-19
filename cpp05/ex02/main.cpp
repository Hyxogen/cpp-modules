#include <cassert>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define ASSERT_THROW(x, type)                                                  \
 try {                                                                         \
  x;                                                                           \
  assert(0 && "Did not throw");                                                \
 } catch (const type &ex) {                                                    \
  (void) ex;                                                                   \
 } catch (const std::exception &ex) {                                          \
  assert(0 && "Threw something else");                                         \
 }

#define ASSERT_NOTHROW(x)                                                      \
 try {                                                                         \
  x;                                                                           \
 } catch (const std::exception &ex) {                                          \
  (void) ex;                                                                   \
  assert(0 && "Did throw");                                                    \
 }

#define ASSERT_EQUAL(a, b) assert((a == b) && "Not equal")

void bcrat_tests() {
        ASSERT_THROW(
            Bureaucrat("nobody", MIN_GRADE + 1),
            Bureaucrat::GradeTooLowException);
        ASSERT_THROW(
            Bureaucrat("nobody", MAX_GRADE - 1),
            Bureaucrat::GradeTooHighException);

        Bureaucrat br("stanley", MIN_GRADE);

        ASSERT_EQUAL(br.getName(), "stanley");
        ASSERT_EQUAL(br.getGrade(), MIN_GRADE);

        ASSERT_THROW(br.demote(), Bureaucrat::GradeTooLowException);
        ASSERT_NOTHROW(br.promote());
        ASSERT_EQUAL(br.getGrade(), MIN_GRADE - 1);

        std::cout << br << std::endl;

        Bureaucrat other("other", MAX_GRADE);
        ASSERT_THROW(other.promote(), Bureaucrat::GradeTooHighException);
        ASSERT_NOTHROW(other.demote());
        ASSERT_EQUAL(other.getGrade(), MAX_GRADE + 1);

        std::cout << other << std::endl;
}

void form_tests() {
        ASSERT_THROW(
            Form("nothing", MIN_GRADE + 1, MIN_GRADE),
            Form::GradeTooLowException);
        ASSERT_THROW(
            Form("nothing", MIN_GRADE, MIN_GRADE + 1),
            Form::GradeTooLowException);
        ASSERT_THROW(
            Form("nothing", MAX_GRADE - 1, MIN_GRADE),
            Form::GradeTooHighException);
        ASSERT_THROW(
            Form("nothing", MIN_GRADE, MAX_GRADE - 1),
            Form::GradeTooHighException);

        Bureaucrat super("super", MAX_GRADE);
        Bureaucrat stanley("stanley", MIN_GRADE);
        Form       simple("simple", MAX_GRADE + 1, MIN_GRADE);

        ASSERT_EQUAL(simple.getName(), "simple");
        ASSERT_EQUAL(simple.getMinSignGrade(), MAX_GRADE + 1);
        ASSERT_EQUAL(simple.getMinExecGrade(), MIN_GRADE);
        ASSERT_EQUAL(simple.isSigned(), false);

        ASSERT_NOTHROW(simple.beSigned(super));
        ASSERT_EQUAL(simple.isSigned(), true);

        ASSERT_THROW(simple.beSigned(stanley), Form::GradeTooLowException);
        ASSERT_EQUAL(simple.isSigned(), true);

        Form other("other", MAX_GRADE, MAX_GRADE);
        ASSERT_THROW(simple.beSigned(stanley), Form::GradeTooLowException);
        ASSERT_EQUAL(other.isSigned(), false);

        ASSERT_NOTHROW(simple.beSigned(super));
        ASSERT_EQUAL(simple.isSigned(), true);

        stanley.signForm(simple);
        std::cout << simple << std::endl;
        std::cout << other << std::endl;
}

void shrubbery_tests() {
        ShrubberyCreationForm shub("something");
        ASSERT_EQUAL(shub.getTarget(), "something");
        ASSERT_EQUAL(shub.getMinSignGrade(), 145);
        ASSERT_EQUAL(shub.getMinExecGrade(), 137);

        Bureaucrat super("super", MAX_GRADE);
        Bureaucrat stanley("stanley", 138);

        ASSERT_THROW(shub.execute(super), Form::NotSignedException);
        ASSERT_NOTHROW(super.executeForm(shub));

        ASSERT_NOTHROW(shub.beSigned(super));

        ASSERT_THROW(shub.execute(stanley), Form::GradeTooLowException);
        ASSERT_NOTHROW(stanley.executeForm(shub));
        ASSERT_NOTHROW(shub.execute(super));

        ASSERT_NOTHROW(stanley.promote());
        ASSERT_NOTHROW(shub.execute(stanley));

	ShrubberyCreationForm copy("temporary");
	copy = shub;
        ASSERT_EQUAL(copy.getTarget(), "something");
        ASSERT_EQUAL(copy.getMinSignGrade(), 145);
        ASSERT_EQUAL(copy.getMinExecGrade(), 137);
}

void robotomy_tests() {
        RobotomyRequestForm rob("stanley");
        ASSERT_EQUAL(rob.getTarget(), "stanley");
        ASSERT_EQUAL(rob.getMinSignGrade(), 72);
        ASSERT_EQUAL(rob.getMinExecGrade(), 45);

        Bureaucrat super("super", MAX_GRADE);
        Bureaucrat stanley("stanley", 46);

        ASSERT_THROW(rob.execute(super), Form::NotSignedException);
        ASSERT_NOTHROW(super.executeForm(rob));
        ASSERT_NOTHROW(rob.beSigned(super));

        ASSERT_THROW(rob.execute(stanley), Form::GradeTooLowException);
        ASSERT_NOTHROW(stanley.executeForm(rob));
        ASSERT_NOTHROW(rob.execute(super));

        ASSERT_NOTHROW(stanley.promote());
        ASSERT_NOTHROW(rob.execute(stanley));

        ASSERT_NOTHROW(stanley.executeForm(rob));
        ASSERT_NOTHROW(super.executeForm(rob));

	RobotomyRequestForm copy("temporary");
	copy = rob;
        ASSERT_EQUAL(copy.getTarget(), "stanley");
        ASSERT_EQUAL(copy.getMinSignGrade(), 72);
        ASSERT_EQUAL(copy.getMinExecGrade(), 45);
}

void president_tests() {
        PresidentialPardonForm pres("stanley");
        ASSERT_EQUAL(pres.getTarget(), "stanley");
        ASSERT_EQUAL(pres.getMinSignGrade(), 25);
        ASSERT_EQUAL(pres.getMinExecGrade(), 5);

        Bureaucrat super("super", MAX_GRADE);
        Bureaucrat stanley("stanley", 6);

        ASSERT_THROW(pres.execute(super), Form::NotSignedException);
        ASSERT_NOTHROW(super.executeForm(pres));
        ASSERT_NOTHROW(pres.beSigned(super));

        ASSERT_THROW(pres.execute(stanley), Form::GradeTooLowException);
        ASSERT_NOTHROW(stanley.executeForm(pres));
        ASSERT_NOTHROW(pres.execute(super));

        ASSERT_NOTHROW(stanley.promote());
        ASSERT_NOTHROW(pres.execute(stanley));

        ASSERT_NOTHROW(stanley.executeForm(pres));
        ASSERT_NOTHROW(super.executeForm(pres));

	PresidentialPardonForm copy("temporary");
	copy = pres;
        ASSERT_EQUAL(copy.getTarget(), "stanley");
        ASSERT_EQUAL(copy.getMinSignGrade(), 25);
        ASSERT_EQUAL(copy.getMinExecGrade(), 5);
}

int main() {
        bcrat_tests();
        form_tests();
        shrubbery_tests();
        robotomy_tests();
        president_tests();
        return 0;
}
