#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
        std::string _target;

        PresidentialPardonForm(); /* deleted */
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);

        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        void execute(const Bureaucrat &bcrat) const;

        const std::string &getTarget() const;
};
#endif /* PRESIDENTIALPARDONFORM_HPP */
