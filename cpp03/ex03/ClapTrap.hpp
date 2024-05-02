#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string const& name);
		ClapTrap(ClapTrap const& o);
		~ClapTrap(void);

		ClapTrap&	operator=(ClapTrap const& o);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int const amount);
		void	beRepaired(unsigned int const amount);

	protected:
		bool	canDoAction(std::string const& action) const;

	protected:
		std::string		m_name;
		unsigned int	m_hp;
		unsigned int	m_ep;
		unsigned int	m_ad;
};

#endif
