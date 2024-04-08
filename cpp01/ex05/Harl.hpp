#ifndef HARL_H
# define HARL_H

# include <iostream>

class Harl
{
	public:
		typedef void	(Harl::*t_func)(void);
		void	complain(std::string level);

	private:
		void			debug(void);
		void			info(void);
		void			warning(void);
		void			error(void);

		static const t_func	g_funcs[4];
		static const char	*g_levels[4];
};

#endif