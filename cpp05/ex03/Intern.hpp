#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {
private:
	struct FormEntry {
		std::string type;
		Form *(*func)(const std::string &target);
	};

	static const FormEntry ENTRIES[3];
public:
	Intern();
	Intern(const Intern &other);

	~Intern();

	Intern &operator=(const Intern &other);

	Form *createForm(const std::string &type, const std::string &target) const;
private:
	template<typename T>
	static Form *createForm(const std::string &target) {
		return new T(target);
	}

};
#endif
