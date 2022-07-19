#include <cassert>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

#define ASSERT_THROW(x, type)                                                  \
 try {                                                                         \
  x;                                                                           \
  assert(0 && "Did not throw");                                                \
 } catch (const type &ex) {                                                    \
  (void) ex;                                                                   \
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
        Form       simple("simple", MAX_GRADE, MIN_GRADE);

        ASSERT_EQUAL(simple.getName(), "simple");
        ASSERT_EQUAL(simple.getMinSignGrade(), MAX_GRADE);
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

        std::cout << simple << std::endl;
        std::cout << other << std::endl;
}

int main() {
        bcrat_tests();
        form_tests();
        return 0;
}
