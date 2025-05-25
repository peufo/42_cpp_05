#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeRequiredToSign;
		const int gradeRequiredToExecute;
		virtual void execute(Bureaucrat const & executor) const = 0;
	public:
		virtual ~AForm();
		AForm();
		AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		void beSigned(Bureaucrat&);
		void tryExecute(Bureaucrat const & executor) const;
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
		class ExecutionException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SignRequiredException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
