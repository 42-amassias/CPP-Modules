#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("shrubbery creation form", 145, 137),
	m_target("Unknown target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("shrubbery creation form", 145, 137),
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
		<< "    ###     "  << "    ###     "  << "    ###     "  << std::endl
		<< "   #o###    "  << "   #o###    "  << "   #o###    "  << std::endl
		<< " #####o###  "  << " #####o###  "  << " #####o###  "  << std::endl
		<< "#o#\\#|#/### " << "#o#\\#|#/### " << "#o#\\#|#/### " << std::endl
		<< " ###\\|/#o#  " << " ###\\|/#o#  " << " ###\\|/#o#  " << std::endl
		<< "  # }|{  #  "  << "  # }|{  #  "  << "  # }|{  #  "  << std::endl
		<< "    }|{     "  << "    }|{     "  << "    }|{     "  << std::endl;
	f.close();
}
