#include "Fixed.hpp"

typedef unsigned int	uint32_t;
typedef unsigned long	uint64_t;

Fixed::Fixed(Fixed const& o) :
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

Fixed::Fixed(int const integer) :
	m_value(integer << Fixed::frac_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

#define	CREATE_MASK(w) ((1L << (w)) - 1L)

static uint32_t const	IEEE754_EXP_BIT_WIDTH = 8;
static uint32_t const	IEEE754_EXP_OFFSET = +127;
static uint32_t const	IEEE754_MANTISSA_BIT_WIDTH = 23;

// Returns the exponent of a IEEE754 float.
inline
uint32_t	_get_IEEE754_exp(float const value)
{
	uint32_t const	EXP_MASK = CREATE_MASK(IEEE754_EXP_BIT_WIDTH);
	uint32_t		_exp(*(uint32_t *)&value);

	_exp >>= IEEE754_MANTISSA_BIT_WIDTH;
	_exp &= EXP_MASK;
	_exp -= IEEE754_EXP_OFFSET;
	_exp &= EXP_MASK;
	return (_exp);
}

// Returns the mantissa of a IEEE754 float with the implicit bit set.
inline
uint32_t	_get_IEEE754_mts(float const value)
{
	uint32_t const	MTS_MASK = CREATE_MASK(IEEE754_MANTISSA_BIT_WIDTH);
	uint32_t		_mst(*(uint32_t *)&value);

	return((_mst & MTS_MASK) | (MTS_MASK + 1));
}

Fixed::Fixed(float const value) :
	m_value(0)
{
	uint32_t	exp = _get_IEEE754_exp(value);
	uint64_t	mts = _get_IEEE754_mts(value);

	// Shifting the mantissa using the exponent
	if (exp < 0)
		mts >>= -exp;
	if (exp > 0)
		mts <<= exp;
	// Setting the integer part
	m_value = mts >> (23 - Fixed::frac_bits);
	// Masking out the fractional bits
	m_value &= ~CREATE_MASK(Fixed::frac_bits);
	// Setting the fractional part
	m_value |= (mts >> (23 - Fixed::frac_bits)) & CREATE_MASK(Fixed::frac_bits);
	std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& o)
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

void	Fixed::setRawBits(int const raw)
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

bool	Fixed::operator>(Fixed const& rhs) const
{
	return (this->m_value > rhs.m_value);
}

bool	Fixed::operator<(Fixed const& rhs) const
{
	return (this->m_value < rhs.m_value);
}

bool	Fixed::operator>=(Fixed const& rhs) const
{
	return (this->m_value >= rhs.m_value);
}

bool	Fixed::operator<=(Fixed const& rhs) const
{
	return (this->m_value <= rhs.m_value);
}

bool	Fixed::operator==(Fixed const& rhs) const
{
	return (this->m_value == rhs.m_value);
}

bool	Fixed::operator!=(Fixed const& rhs) const
{
	return (this->m_value != rhs.m_value);
}

Fixed	Fixed::operator+(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&	Fixed::operator++(void) // prefix
{
	++this->m_value;
	return (*this);
}

Fixed&	Fixed::operator--(void) // prefix
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

Fixed&	Fixed::min(Fixed & a, Fixed & b)
{
	return (a.m_value < b.m_value ? a : b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	return (a.m_value < b.m_value ? a : b);
}

Fixed&	Fixed::max(Fixed & a, Fixed & b)
{
	return (a.m_value > b.m_value ? a : b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	return (a.m_value > b.m_value ? a : b);
}

std::ostream&	operator<<(std::ostream & o, Fixed const& fixed)
{
	o << fixed.toFloat();
	return (o);
}
