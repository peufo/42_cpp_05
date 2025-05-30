#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		static const int GRADE_MAX = 1;
		static const int GRADE_MIN = 150;
		~Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(AForm& AForm);
		void executeForm(AForm const & form) const;
		class GradeTooHighException: public std::exception
		{
			private:
				std::string* msg;
			public:
				virtual ~GradeTooHighException() throw();
				GradeTooHighException(Bureaucrat&);
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			private:
				std::string* msg;
			public:
				virtual ~GradeTooLowException() throw();
				GradeTooLowException(Bureaucrat&);
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& src);

#endif
