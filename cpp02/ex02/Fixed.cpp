#include "Fixed.hpp"

typedef unsigned int	uint32_t;
typedef unsigned long	uint64_t;

Fixed::Fixed(const Fixed &o) :
	m_value(o.m_value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed() :
	m_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) :
	m_value(integer << Fixed::frac_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

#include <bitset>

Fixed::Fixed(const float value) :
	m_value(0)
{
	const uint32_t	_exp = (((*((uint32_t *)&value) >> 23) & 0xFF) - 127) & 0xFF;
	const char		exp = *(char *)&_exp;
	uint64_t		mts = (*((uint64_t *)&value) & 0x7FFFFF) | 0x800000;

	if (exp < 0)
		mts >>= -exp;
	if (exp > 0)
		mts <<= exp;
	m_value = (mts >> (23 - Fixed::frac_bits)) & ((1L << (sizeof(m_value) * 8)) - 1);
	m_value &= ~((1 << Fixed::frac_bits) - 1);
	m_value |= (mts >> (23 - Fixed::frac_bits)) & ((1 << Fixed::frac_bits) - 1);
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &o)
{
	std::cout << "Copy assignment operator called" << std::endl;
	m_value = o.m_value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_value);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	m_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	r;

	r = toInt();
	for (size_t i = 0; i <= Fixed::frac_bits; ++i)
		r += (float)((m_value >> (Fixed::frac_bits - i - 1)) & 1) / (float)(1 << (i + 1));
	return (r);
}

int	Fixed::toInt(void) const
{
	return (m_value >> Fixed::frac_bits);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->m_value > rhs.m_value);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->m_value < rhs.m_value);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->m_value >= rhs.m_value);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->m_value <= rhs.m_value);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->m_value == rhs.m_value);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->m_value != rhs.m_value);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void) // prefix
{
	++this->m_value;
	return (*this);
}

Fixed	&Fixed::operator--(void) // prefix
{
	--this->m_value;
	return (*this);
}

Fixed	Fixed::operator++(int) // postfix
{
	Fixed tmp(*this);
	tmp.m_value = this->m_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int) // postfix
{
	Fixed tmp(*this);
	tmp.m_value = this->m_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a.m_value < b.m_value ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.m_value < b.m_value ? a : b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return (a.m_value > b.m_value ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.m_value > b.m_value ? a : b);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
