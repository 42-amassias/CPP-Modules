#include "ShrubberyCreationForm.hpp"

#include <fstream>

const AForm::grade_t	ShrubberyCreationForm::sign_grade = 145;
const AForm::grade_t	ShrubberyCreationForm::execute_grade = 137;
const std::string		ShrubberyCreationForm::litteral_name = "shrubbery creation";

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm(
		ShrubberyCreationForm::litteral_name,
		ShrubberyCreationForm::sign_grade,
		ShrubberyCreationForm::execute_grade),
	m_target("Unknown target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm(
		ShrubberyCreationForm::litteral_name,
		ShrubberyCreationForm::sign_grade,
		ShrubberyCreationForm::execute_grade),
	m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o) :
	AForm(o),
	m_target(o.m_target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm & o)
{
	if (this == &o)
		return (*this);
	AForm::operator=(o);
	m_target = o.m_target;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkIfCanExecute(executor);
	std::ofstream	f;

	f.open((m_target + std::string("_shrubberry")).c_str());
	if (!f)
		return ;
	f
		<< "    ###     " << "    ###     " << "    ###     " << std::endl
		<< "   #o###    " << "   #o###    " << "   #o###    " << std::endl
		<< " #####o###  " << " #####o###  " << " #####o###  " << std::endl
		<< "#o#\\#|#/### " << "#o#\\#|#/### " << "#o#\\#|#/### " << std::endl
		<< " ###\\|/#o#  " << " ###\\|/#o#  " << " ###\\|/#o#  " << std::endl
		<< "  # }|{  #  " << "  # }|{  #  " << "  # }|{  #  " << std::endl
		<< "    }|{     " << "    }|{     " << "    }|{     " << std::endl;
	f.close();
}
