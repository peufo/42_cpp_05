#include "Bureaucrat.hpp"


void bob()
{
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
		for(int i = 0; i < 41; i++)
			bob.increment();
		std::cout << bob << std::endl;
		bob.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void alice()
{
	for (int i = -5; i < 155; i += 3)
	{
		try
		{
			Bureaucrat alice("Alice", i);
			std::cout << alice << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

int main()
{
	bob();
	alice();
}
