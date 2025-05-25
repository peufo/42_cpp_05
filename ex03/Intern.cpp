#include "Intern.hpp"

Intern::~Intern()
{}

Intern::Intern()
{}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& src)
{
	if(this == &src)
		return *this;
	return *this;
}

AForm* Intern::makeForm(const std::string & formName, const std::string & target) const
{
	static const t_form forms[3] = {
		(t_form){ "shrubbery creation", &newShrubbery },
		(t_form){ "robotomy request", &newRobotomy },
		(t_form){ "presidential pardon", &newPresidential },
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern create" << formName << std::endl;
			return forms[i].newForm(target);
		}
	}
	throw Intern::NotFoundForm();
}

const char *Intern::NotFoundForm::what() const throw()
{
	return "Intern: Sorry form not found";
}

// Private static
AForm* Intern::newShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
AForm* Intern::newRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::newPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
