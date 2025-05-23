#include "Bureaucrat.hpp"

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

std::string Bureaucrat::getName()
{
	return this->name;
}

int Bureaucrat::getGrade()
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

std::ostream& operator<<(std::ostream& os, Bureaucrat& src)
{
	return os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
}
