#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		static const int GRADE_MAX = 1;
		static const int GRADE_MIN = 150;
	public:
		~Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		std::string getName();
		int getGrade();
		void increment();
		void decrement();
		class GradeTooHighException: public std::exception
		{
			private:
				Bureaucrat& bureaucrat;
			public:
				GradeTooHighException(Bureaucrat&);
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			private:
				Bureaucrat& bureaucrat;
			public:
				GradeTooLowException(Bureaucrat&);
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& src);

#endif
