#include "Bureaucrat.hpp"

#include <cassert>
#include <stdexcept>
#include <iostream>

#define ASSERT_THROW(x, type)			\
	try {					\
		x;				\
		assert(0 && "Did not throw");	\
	} catch (const type &ex) {		\
		(void) ex;			\
	}

#define ASSERT_NOTHROW(x)			\
	try {					\
		x;				\
	} catch (const std::exception &ex) {	\
		(void) ex;			\
		assert(0 && "Did throw");	\
	}

#define ASSERT_EQUAL(a, b) assert((a == b) && "Not equal")

int main() {
	Bureaucrat br("stanley", MIN_GRADE);

	ASSERT_EQUAL(br.getName(), "stanley");
	ASSERT_EQUAL(br.getGrade(), MIN_GRADE);

	ASSERT_THROW(br.demote(), Bureaucrat::GradeTooLowException);
	ASSERT_NOTHROW(br.promote());
	ASSERT_EQUAL(br.getGrade(), MIN_GRADE - 1);

	std::cout << br << std::endl;
}
