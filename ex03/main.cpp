#include "Bureaucrat.hpp"
#include "Intern.hpp"

void alice()
{
	std::cout << "\nAlice jobs:" << std::endl;
	Intern intern;
	AForm *form = intern.makeForm("shrubbery creation", "Citizen_A");
	try {
		Bureaucrat alice("Alice", 140);
		alice.executeForm(*form);
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
}

void bob()
{
	std::cout << "\nBob jobs:" << std::endl;
	AForm *form = Intern().makeForm("shrubbery creation", "Citizen_B");
	try
	{
		Bureaucrat bob("Bob", 130);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
}

void clelie()
{
	std::cout << "\nClelie jobs:" << std::endl;
	AForm *form = Intern().makeForm("robotomy request", "Citizen_C");
	try {
		Bureaucrat clelie("Clelie", 43);
		clelie.signForm(*form);
		clelie.executeForm(*form);
		clelie.decrement();
		clelie.executeForm(*form);
		clelie.decrement();
		clelie.executeForm(*form);
		clelie.decrement();
		clelie.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
}

void diane()
{
	std::cout << "\nDiane jobs:" << std::endl;
	AForm *form = Intern().makeForm("presidential pardon", "Citizen_D");
	try
	{
		Bureaucrat diane("Diane", 30);
		while (diane.getGrade() > 1)
		{
			diane.signForm(*form);
			diane.executeForm(*form);
			diane.increment();
			diane.increment();
			diane.increment();
			diane.increment();
			diane.increment();
		}
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	try
	{
		alice();
		bob();
		clelie();
		diane();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
