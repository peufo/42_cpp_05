#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeRequiredToSign;
		const int gradeRequiredToExecute;
	public:
		~Form();
		Form();
		Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		void beSigned(Bureaucrat&);
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
