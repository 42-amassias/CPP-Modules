#include "BitcoinExchange.hpp"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

const BitcoinExchange::database_t	BitcoinExchange::m_price_history = BitcoinExchange::parseBdd();

const size_t	g_data_size = _binary_data_csv_end - _binary_data_csv_start;

BitcoinExchange::database_t	BitcoinExchange::parseBdd(void)
{
	BitcoinExchange::database_t		bdd;
	std::string						s(_binary_data_csv_start, g_data_size);
	std::string						line;
	std::string						date;
	std::string						price;
	std::istringstream				iss(s);

	std::getline(iss, line); // Ignore first line
	while (std::getline(iss, line))
	{
		date = line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
		price = line.substr(11);
		bdd[atoi(date.c_str())] = atof(price.c_str());
	}
	return (bdd);
}

float	BitcoinExchange::getPriceOfDay(int const& date)
{
	return (m_price_history.lower_bound(date)->second);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& o)
{
	*this = o;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& o)
{
	(void)o;
	return (*this);
}
