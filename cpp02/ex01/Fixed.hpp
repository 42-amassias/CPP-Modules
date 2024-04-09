#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public:
		Fixed(const Fixed &o);
		~Fixed();
		
		Fixed();
		Fixed(const int integer);
		Fixed(const float value);

		Fixed	&operator=(const Fixed &o);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		float	toFloat(void) const;
		int		toInt(void) const;
	
	private:
		int					m_value;

		static const int	frac_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif