#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat & bureaucrat):
	msg(new std::string("Bureaucrat exception: " + bureaucrat.getName() + ": Grade too high !")) {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->msg->data();
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	delete this->msg;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat &bureaucrat):
	msg(new std::string("Bureaucrat exception: " + bureaucrat.getName() + ": Grade too low !")) {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->msg->data();
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	delete this->msg;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
	if (this->grade < this->GRADE_MAX)
		throw Bureaucrat::GradeTooHighException(*this);
	if (this->grade > this->GRADE_MIN)
		throw Bureaucrat::GradeTooLowException(*this);
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::increment()
{
	if (this->grade - 1 < this->GRADE_MAX)
		throw Bureaucrat::GradeTooHighException(*this);
	this->grade--;
}
void Bureaucrat::decrement()
{
	if (this->grade + 1 > this->GRADE_MIN)
		throw Bureaucrat::GradeTooLowException(*this);
	this->grade++;
}

void Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name <<  " signed " << form.getName() << " with success 👍" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name <<  " couldn’t sign " << form.getName() << " 🚫 Reason: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.tryExecute(*this);
		std::cout << this->name <<  " execute " << form.getName() << " with success 👍" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name <<  " couldn’t execute " << form.getName() << " 🚫 Reason: " << e.what() << '\n';
	}
	
	
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& src)
{
	return os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
}

