#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

#define DATE_SIZE (10)

static
bool	_is_digit(
			std::string const& s
			);

static
float	_to_float(
			std::string const& ratio
			);

static
bool	_check_date(
			std::string const& date
			);

static
void	_treat_file(
			const char *fn
			);
static
void	_treat_line(
			std::string const& line
			);
static
void	_computeLine(
			std::string const& date,
			std::string const& ratio
			);

int	main(
		int argc,
		char **argv
		)
{

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	_treat_file(argv[1]);
	return (EXIT_SUCCESS);
}

static
bool	_is_digit(
			std::string const& s
			)
{
	std::string::const_iterator it(s.begin());

	for (; it != s.end() && std::isdigit(*it); ++it);
	return (!s.empty() && it == s.end());
}

static
float	_to_float(
			std::string const& ratio
			)
{
	std::stringstream	ss;
	float				r;
	size_t				end;

	end = ratio.find_last_not_of(' ');
	end += ratio.find_last_not_of(' ') != std::string::npos ? 1 : 0;
	ss << ratio.substr(0, end);
	if (!(ss >> r) || !ss.eof())
		throw std::exception();
	return (r);
}

static
bool	_check_date(
			std::string const& date
			)
{
	std::string	year(date.substr(0, 4));
	std::string	month(date.substr(5, 2));
	std::string	day(date.substr(8, 2));
	int			d;
	int			m;
	int			y;

	if (!_is_digit(year)
		|| !_is_digit(month)
		|| !_is_digit(day)
		|| date[4] != '-'
		|| date[7] != '-'
		)
		return (false);
	d = atoi(day.c_str());
	m = atoi(month.c_str());
	y = atoi(year.c_str());
	if (!(1 <= m && m <= 12))
		return (false);
	if (!(1 <= d && d <= 31))
		return (false);
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		return (false);
	if ((d == 30) && (m == 2))
		return (false);
	if ((m == 2) && (d == 29) && (y % 4 != 0))
		return (false);
	if ((m == 2) && (d == 29) && (y % 400 == 0))
		return (true);
	if ((m == 2) && (d == 29) && (y % 100 == 0))
		return (false);
	if ((m == 2) && (d == 29) && (y % 4 == 0))
		return (true);
	return (true);
}

static
void	_treat_file(
			const char *fn
			)
{
	std::ifstream	file;
	std::string		line;

	file.open(fn);
	std::getline(file, line);
	while (std::getline(file, line))
		_treat_line(line);
}

static
void	_treat_line(
			std::string const& line
			)
{
	std::size_t	date_start(line.find_first_not_of(' '));
	std::size_t	ratio_start(line.find_first_of('|'));
	std::string	date;
	std::string	ratio;

	if (date_start + DATE_SIZE > ratio_start || ratio_start == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	date = line.substr(date_start, DATE_SIZE);
	ratio_start = line.find_first_not_of(' ', ratio_start + 1);
	try
	{
		ratio = line.substr(ratio_start);
	}
	catch (std::out_of_range const& e)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	_computeLine(date, ratio);
}

static
void	_computeLine(
			std::string const& date,
			std::string const& ratio
			)
{
	std::string	subdate;
	float		price;
	float		fratio;

	if (!_check_date(date))
	{
		std::cerr << "Error: bad day format => " << date << std::endl;
		return ;
	}
	subdate = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
	price = BitcoinExchange::getPriceOfDay(atoi(subdate.c_str()));
	try
	{
		fratio = _to_float(ratio);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: not a number => " << ratio << std::endl;
		return ;
	}
	if (fratio < 0.f)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (fratio > 1000.f)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}
	std::cout
		<< date
		<< " => "
		<< fratio 
		<< " = "
		<< price * fratio
		<< std::endl;
}
