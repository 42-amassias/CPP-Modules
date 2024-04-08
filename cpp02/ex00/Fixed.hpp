#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed &o);
		~Fixed();

		Fixed	&operator=(Fixed &o);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
	
	private:
		int					m_value;

		static const int	frac_bits = 8;
};

#endif