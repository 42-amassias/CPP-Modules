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

		Fixed				&operator=(Fixed const& o);

		int					getRawBits(void) const;
		void				setRawBits(const int raw);

		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator>(Fixed const& rhs) const;
		bool				operator<(Fixed const& rhs) const;
		bool				operator>=(Fixed const& rhs) const;
		bool				operator<=(Fixed const& rhs) const;
		bool				operator==(Fixed const& rhs) const;
		bool				operator!=(Fixed const& rhs) const;

		Fixed				operator+(Fixed const& rhs) const;
		Fixed				operator-(Fixed const& rhs) const;
		Fixed				operator*(Fixed const& rhs) const;
		Fixed				operator/(Fixed const& rhs) const;

		Fixed&				operator++(void); // prefix
		Fixed&				operator--(void); // prefix
		Fixed				operator++(int); // postfix
		Fixed				operator--(int); // postfix

		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);
	
	private:
		int					m_value;

		static const int	frac_bits = 8;
};

std::ostream&	operator<<(std::ostream & o, Fixed const& fixed);

#endif