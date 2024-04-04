#include "Account.hpp"

#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts(0);
int	Account::_totalAmount(0);
int	Account::_totalNbDeposits(0);
int	Account::_totalNbWithdrawals(0);

Account::Account(int initial_deposit) :
	_accountIndex(Account::_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created"
		<< std::endl;
}

Account::Account(void) :
	_accountIndex(Account::_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
}

Account::~Account(void)
{
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _totalNbWithdrawals;
	--_nbAccounts;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed"
		<< std::endl;
}

void		Account::makeDeposit(int deposit)
{
	const int	previous_amount = _amount;

	++_nbDeposits;
	++_totalNbDeposits;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << previous_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	const int	previous_amount = _amount;

	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << previous_amount << ";"
		<< "withdrawal:refused"
		<< std::endl;
		return (false);
	}
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << previous_amount << ";"
	<< "withdrawal:" << withdrawal << ";"
	<< "amount:" << _amount << ";"
	<< "nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	return (true);
}

int			Account::checkAmount(void) const
{
	return (_amount);
}

void		Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}


#ifdef DIFF_MODE
void	Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}
#else
void	Account::_displayTimestamp(void)
{
	time_t now = std::time(NULL);
	struct tm timenow = *std::localtime(&now);

	std::cout
		<< "["
		<< timenow.tm_year + 1900
		<< std::setfill('0') << std::setw(2) << timenow.tm_mon + 1
		<< std::setfill('0') << std::setw(2) << timenow.tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2) << timenow.tm_hour
		<< std::setfill('0') << std::setw(2) << timenow.tm_min
		<< std::setfill('0') << std::setw(2) << timenow.tm_sec
		<< "] ";
}
#endif