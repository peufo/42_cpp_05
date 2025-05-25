#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void alice()
{
	std::cout << "\nAlice jobs:" << std::endl;
	Bureaucrat alice("Alice", 140);
	ShrubberyCreationForm form("Citizen_A");
	alice.executeForm(form);
	alice.signForm(form);
	alice.executeForm(form);
}

void bob()
{
	std::cout << "\nBob jobs:" << std::endl;
	Bureaucrat bob("Bob", 130);
	ShrubberyCreationForm form("Citizen_B");
	bob.signForm(form);
	bob.executeForm(form);
}

void clelie()
{
	std::cout << "\nClelie jobs:" << std::endl;
	Bureaucrat clelie("Clelie", 43);
	RobotomyRequestForm form("Citizen_C");
	clelie.signForm(form);
	clelie.executeForm(form);
	clelie.decrement();
	clelie.executeForm(form);
	clelie.decrement();
	clelie.executeForm(form);
	clelie.decrement();
	clelie.executeForm(form);
}

void diane()
{
	std::cout << "\nDiane jobs:" << std::endl;
	Bureaucrat diane("Diane", 30);
	PresidentialPardonForm form("Citizen_D");
	while (diane.getGrade() > 1)
	{
		diane.signForm(form);
		diane.executeForm(form);
		diane.increment();
		diane.increment();
		diane.increment();
		diane.increment();
		diane.increment();
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
