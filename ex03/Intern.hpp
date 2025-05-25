#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		typedef struct {
			std::string name;
			AForm* (*newForm)(const std::string&);
		}	t_form;
		static AForm* newShrubbery(const std::string& target);
		static AForm* newRobotomy(const std::string& target);
		static AForm* newPresidential(const std::string& target);
	public:
		~Intern();
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		AForm* makeForm(const std::string& formName, const std::string& target) const;
		class NotFoundForm: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
