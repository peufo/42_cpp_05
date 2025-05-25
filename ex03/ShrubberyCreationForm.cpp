#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("Shrubbery creation", 145, 137),
	target(target)
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::ofstream os(std::string(this->target + "_shrubbery").c_str(), std::ios::trunc);
	if (!os)
		throw AForm::ExecutionException();
	os << this->target << "'s shrubbery" << "\n";
	os << "\n";
	os << "    oxoxoo    ooxoo\n";
	os << "  ooxoxo oo  oxoxooo\n";
	os << " oooo xxoxoo ooo ooox\n";
	os << " oxo o oxoxo  xoxxoxo\n";
	os << "  oxo xooxoooo o ooo\n";
	os << "    ooo\\oo\\  /o/o\n";
	os << "        \\  \\/ /\n";
	os << "         |   /\n";
	os << "         |  |\n";
	os << "         | D|\n";
	os << "         |  |\n";
	os << "         |  |\n";
	os << "  ______/____\\____\n";
	os.close();
}