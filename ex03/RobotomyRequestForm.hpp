#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
		void execute(Bureaucrat const & executor) const;
	public:
		RobotomyRequestForm(const std::string& target);
};

#endif
