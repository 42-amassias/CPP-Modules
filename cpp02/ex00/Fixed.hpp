#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& o);
		~Fixed();

		Fixed	&operator=(Fixed const& o);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
	
	private:
		int					m_value;

		static const int	frac_bits = 8;
};

#endif