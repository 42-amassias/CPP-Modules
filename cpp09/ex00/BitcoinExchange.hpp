#ifndef  BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

extern "C" const char _binary_data_csv_start[];
extern "C" const char _binary_data_csv_end[];

class BitcoinExchange
{
	public:
		typedef
			std::map<int, float, std::greater<int> >
			database_t;

	public:
		static float		getPriceOfDay(int const& date);

	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const& o);
		~BitcoinExchange(void);

	private:
		BitcoinExchange&	operator=(BitcoinExchange const& o);

	private:
		static database_t	parseBdd(void);
	
	private:
		static const database_t	m_price_history;
};

#endif
