#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &o);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &o);

		void	attack(const std::string &target);
		void	takeDamage(const unsigned int amount);
		void	beRepaired(const unsigned int amount);

	private:
		bool	canDoAction(const std::string &action) const;

	private:
		std::string		m_name;
		unsigned int	m_hp;
		unsigned int	m_ep;
		unsigned int	m_ad;
};

#endif