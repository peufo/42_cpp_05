#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("Presidential pardon", 25, 5),
	target(target)
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << this->target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}
