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

		Fixed				&operator=(const Fixed &o);

		int					getRawBits(void) const;
		void				setRawBits(const int raw);

		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator>(const Fixed &rhs) const;
		bool				operator<(const Fixed &rhs) const;
		bool				operator>=(const Fixed &rhs) const;
		bool				operator<=(const Fixed &rhs) const;
		bool				operator==(const Fixed &rhs) const;
		bool				operator!=(const Fixed &rhs) const;

		Fixed				operator+(const Fixed &rhs) const;
		Fixed				operator-(const Fixed &rhs) const;
		Fixed				operator*(const Fixed &rhs) const;
		Fixed				operator/(const Fixed &rhs) const;

		Fixed				&operator++(void); // prefix
		Fixed				&operator--(void); // prefix
		Fixed				operator++(int); // postfix
		Fixed				operator--(int); // postfix

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	
	private:
		int					m_value;

		static const int	frac_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif