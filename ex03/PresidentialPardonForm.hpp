#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;
		void execute(Bureaucrat const & executor) const;
	public:
		PresidentialPardonForm(const std::string& target);
};

#endif
