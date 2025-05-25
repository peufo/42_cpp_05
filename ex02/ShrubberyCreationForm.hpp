#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
		void execute(Bureaucrat const & executor) const;
	public:
		ShrubberyCreationForm(const std::string& target);
};

#endif
