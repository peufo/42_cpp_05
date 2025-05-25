#include "Form.hpp"

Form::~Form()
{
}

Form::Form():
	name("undefined"),
	isSigned(false),
	gradeRequiredToSign(1),
	gradeRequiredToExecute(1)
{}

Form::Form(const std::string & name, int gradeRequiredToSign, int gradeRequiredToExecute):
	name(name),
	isSigned(false),
	gradeRequiredToSign(gradeRequiredToSign),
	gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < Bureaucrat::GRADE_MAX || gradeRequiredToExecute < Bureaucrat::GRADE_MAX)
		throw Form::GradeTooHighException();
	if (gradeRequiredToSign > Bureaucrat::GRADE_MIN || gradeRequiredToExecute > Bureaucrat::GRADE_MIN)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src):
	name(src.name),
	isSigned(src.isSigned),
	gradeRequiredToSign(src.gradeRequiredToSign),
	gradeRequiredToExecute(src.gradeRequiredToExecute)
{}

Form& Form::operator=(const Form& src)
{
	if(this == &src)
		return *this;
	this->isSigned = src.isSigned;
	return *this;
}

const std::string & Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeRequiredToSign() const
{
	return this->gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
	return this->gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeRequiredToSign())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}


const char *Form::GradeTooLowException::what() const throw()
{
	return "Form: grade too low !";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form: grade too high !";
}

std::ostream & operator<<(std::ostream & os, const Form & form)
{
	return os << "Form "
		<< form.getName()
		<< (form.getIsSigned() ? " is signed.\n" : " is not signed.\n")
		<< "Required grade to sign it: " << form.getGradeRequiredToSign() << "\n"
		<< "Required grade to execute it: " << form.getGradeRequiredToExecute() << "\n";
}

