#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("Robotomy request", 72, 45),
	target(target)
{
	std::srand(std::time(NULL));
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "VRRrRRRrRRr, BZzZRzZrZRZRZzRRzR, VRRBRBrBr, ... ?" << std::endl;
	double random = static_cast<double>(std::rand()) / RAND_MAX;
	if (random < 0.5)
		std::cout << this->target << " has been robotomized with success 🤖" << std::endl;
	else
		std::cout << "Oops ! " << this->target << " has not been robotomized 🤡" << std::endl;
}
