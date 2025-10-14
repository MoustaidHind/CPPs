#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0; 
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	_amount = initial_deposit;
	_totalAmount += checkAmount();
};

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << 
	"accounts:" << getNbAccounts() << ";total:" << getTotalAmount() <<
	";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() <<
	std::endl;
	_totalAmount = 0;
};

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << 
	"index:" << _accountIndex<< ";amount:" << checkAmount() << ";deposits:" << _nbDeposits <<
	";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{	
	_nbDeposits++;
	int p_amount = checkAmount() + deposit;

	Account::_displayTimestamp();
	std::cout << 
	"index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit <<
	";amount:" << p_amount << ";nb_deposits:" << _nbDeposits
	<< std::endl;

	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += checkAmount();
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = -1;

	if(_amount - withdrawal >= 0)
		p_amount = _amount - withdrawal;

	Account::_displayTimestamp();
	std::cout << 
	"index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:" ;

	if ( p_amount == -1 )
	{
		std::cout << "refused" << std::endl;
		_totalAmount += checkAmount();
		return(0);
	}

	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" <<  p_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount = p_amount;
	_totalNbWithdrawals++;
	_totalAmount += checkAmount();
	
	return(2);
};

void Account::_displayTimestamp(void)
{
	char buffer[20];
    
	std::time_t now = std::time(NULL);
    std::tm *local_tm = std::localtime(&now);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_tm);
	std::cout << buffer;
}

Account::~Account( void ) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= checkAmount();
}