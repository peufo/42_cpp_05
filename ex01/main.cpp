#include "Bureaucrat.hpp"
#include "Form.hpp"

void bob()
{
	std::cout << "\nBob jobs:" << std::endl;
	Bureaucrat bob("Bob", 20);
	Form formA("Solde contract", 30, 10);
	Form formB("Bridge construction", 10, 10);
	Form formC("Road construction", 20, 10);

	bob.signForm(formA);
	bob.signForm(formB);
	bob.signForm(formC);
}

void alice()
{
	std::cout << "\nAlice jobs:" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 20);
		Form formA("Basic contract", 12, 150);
		Form formB("Mafia contract", 12, 151);
		alice.signForm(formA); // no exectued
		alice.signForm(formB); // no exectued
	}
	catch(const std::exception& e)
	{
		std::cerr << "Something is wrong with Alice jobs ! -> " << e.what() << '\n';
	}
}

int main()
{
	bob();
	alice();
}
