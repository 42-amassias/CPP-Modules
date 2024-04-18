#include "ScalarConverter.hpp"

#include <string>
#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter(void)
{
}

void	ScalarConverter::convert(const std::string &litteral)
{
	char	c;
	int		i;
	float	f;
	double	d;
	bool	impossible = false;
	char	*_;

	switch (ScalarConverter::guessType(litteral))
	{
		case TYPE_CHAR:
			c = litteral[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case TYPE_INT:
			i = std::strtol(litteral.c_str(), &_, 10);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case TYPE_FLOAT:
			f = std::strtof(litteral.c_str(), &_);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break ;
		case TYPE_DOUBLE:
			d = std::strtod(litteral.c_str(), &_);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break ;
		default:
			c = d = i = f = 0;
			impossible = true;
			break ;
	};
	{
		std::cout << "char: ";
		if (impossible || !isprint(c))
			std::cout << "impossible";
		else
			std::cout << c;
		std::cout
			<< std::endl;
	}
	{
		bool	has_sign = litteral[0] == '+' || litteral[0] == '-';
		bool	is_char = litteral.length() == 1;
		std::cout << "int: ";
		if (!impossible
			&& (is_char || !has_sign || isdigit(litteral[1]))
			&& (is_char || has_sign || isdigit(litteral[0])))
			std::cout << i;
		else
			std::cout << "impossible";
		std::cout << std::endl;
	}
	{
		std::cout
			<< "float: ";
		if (impossible)
			std::cout << "impossible";
		else
		{
			std::cout << f;
			if (
				(!(f == f) || std::abs(f) != std::numeric_limits<float>::infinity())
				&& f - static_cast<int>( f ) == 0)
				std::cout << ".0";
			std::cout << 'f';
		}
		std::cout << std::endl;
	}
	{
		std::cout
			<< "double: ";
		if (impossible)
			std::cout << "impossible";
		else
		{
			const bool	is_nan = !(f == f);
			const bool	is_inf = std::abs(f) != std::numeric_limits<float>::infinity();
			const bool	has_decimal_part = f - static_cast<int>(f) == 0;
			std::cout << f;
			if (!is_nan && !is_inf && has_decimal_part)
				std::cout << ".0";
		}
		std::cout << std::endl;
	}
}

ScalarConverter::type_t	ScalarConverter::guessType(const std::string &litteral)
{
	typedef bool	(*type_guesser_fun_t)(const std::string &);
	typedef struct { type_guesser_fun_t guesser; ScalarConverter::type_t type; } type_guesser_t;
	static const type_guesser_t	guessers[TYPE__COUNT - 1] = {
		{ ScalarConverter::isTypeChar, TYPE_CHAR },
		{ ScalarConverter::isTypeInt, TYPE_INT },
		{ ScalarConverter::isTypeFloat, TYPE_FLOAT },
		{ ScalarConverter::isTypeDouble, TYPE_DOUBLE },
	};
	for (size_t i = 0; i < TYPE__COUNT - 1; ++i)
	{
		if (guessers[i].guesser(litteral))
			return (guessers[i].type);
	}
	return (TYPE_UNKNOWN);
}

bool	ScalarConverter::isTypeChar(const std::string &litteral)
{
	return (litteral.length() == 1
		&& isalpha(litteral[0])
		&& isprint(litteral[0])
		);
}

bool	ScalarConverter::isTypeInt(const std::string &litteral)
{
	size_t	index = 0;

	if (litteral[0] == '+' || litteral[0] == '-')
		++index;
	for (; index < litteral.length(); ++index)
		if (!isdigit(litteral[index]))
			return (false);
	return (true);
}

bool	ScalarConverter::isTypeFloat(const std::string &litteral)
{
	return (litteral.length() > 0 && litteral[litteral.length() - 1] == 'f'
			? ScalarConverter::isTypeDouble(litteral.substr(0, litteral.length() - 1))
			: false
			);
}

bool	ScalarConverter::isTypeDouble(const std::string &litteral)
{
	bool		has_dot = false;
	char		c;
	std::string	str = litteral;

	if (litteral.length() == 0 ||
		str.length() < 1 + (str.find('.') == std::string::npos ? 0 : 1))
		return false;
	if (str[0] == '+' || str[0] == '-')
		str = litteral.substr(1, litteral.length());
	if (str == "inf" || str == "nan")
		return (true);
	for (size_t index = 0; index < str.length(); ++index)
	{
		c = str[index];
		if (c == '.')
		{
			if (has_dot)
				return false;
			has_dot = true;
		}
		else if (!isdigit(c))
			return false;
	}
	return (true);
}
