#include "AForm.hpp"

AForm::~AForm()
{}

AForm::AForm():
	name("undefined"),
	isSigned(false),
	gradeRequiredToSign(1),
	gradeRequiredToExecute(1)
{}

AForm::AForm(const std::string & name, int gradeRequiredToSign, int gradeRequiredToExecute):
	name(name),
	isSigned(false),
	gradeRequiredToSign(gradeRequiredToSign),
	gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < Bureaucrat::GRADE_MAX || gradeRequiredToExecute < Bureaucrat::GRADE_MAX)
		throw AForm::GradeTooHighException();
	if (gradeRequiredToSign > Bureaucrat::GRADE_MIN || gradeRequiredToExecute > Bureaucrat::GRADE_MIN)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src):
	name(src.name),
	isSigned(src.isSigned),
	gradeRequiredToSign(src.gradeRequiredToSign),
	gradeRequiredToExecute(src.gradeRequiredToExecute)
{}

AForm& AForm::operator=(const AForm& src)
{
	if(this == &src)
		return *this;
	this->isSigned = src.isSigned;
	return *this;
}

const std::string & AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeRequiredToSign() const
{
	return this->gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
	return this->gradeRequiredToExecute;
}

void AForm::beSigned(Bureaucrat &signator)
{
	if (signator.getGrade() > this->getGradeRequiredToSign())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void AForm::tryExecute(Bureaucrat const & executor) const
{
	if (!this->isSigned)
		throw AForm::SignRequiredException();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw AForm::GradeTooLowException();
	this->execute(executor);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm: grade too low !";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm: grade too high !";
}

const char *AForm::ExecutionException::what() const throw()
{
	return "AForm: something went wrong with execution !";
}

const char *AForm::SignRequiredException::what() const throw()
{
	return "AForm: Signature is required before execution !";
}

std::ostream & operator<<(std::ostream & os, const AForm & Aform)
{
	return os << "AForm "
		<< Aform.getName()
		<< (Aform.getIsSigned() ? " is signed.\n" : " is not signed.\n")
		<< "Required grade to sign it: " << Aform.getGradeRequiredToSign() << "\n"
		<< "Required grade to execute it: " << Aform.getGradeRequiredToExecute() << "\n";
}

