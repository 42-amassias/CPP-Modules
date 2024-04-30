#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public:
		Fixed(Fixed const& o);
		~Fixed();

		Fixed();
		Fixed(int const integer);
		Fixed(float const value);

		Fixed&			operator=(Fixed const& o);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);

		float			toFloat(void) const;
		int				toInt(void) const;

	private:
		int					m_value;

		static int const	frac_bits = 8;
};

std::ostream&	operator<<(std::ostream & o, Fixed const& fixed);

#endif