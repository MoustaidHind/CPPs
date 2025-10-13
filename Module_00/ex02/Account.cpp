#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0; 
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* 
	static int	getNbAccounts( void ); 
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void ); // (in test) 1,4
*/
/* 
	static int	_nbAccounts; 
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;
 */
/* 
	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;
*/


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

Account::Account( int initial_deposit ) //constructor
{
	// Account::_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	// [19920104_091532] index:2;amount:957;created
};

void	Account::displayAccountsInfos( void )
{
	// std::cout  <<  std::endl <<  std::endl;

	// Account::_displayTimestamp();
	std::cout << 
	"accounts:" << getNbAccounts() << ";total:" << getTotalAmount() <<
	";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() <<
	std::endl;

	_nbAccounts = 0; 
	_totalAmount = 0;

	// std::cout  <<  std::endl <<  std::endl;

	
	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0  JUST ONE LINE

};

void	Account::displayStatus( void ) const
{

	// Account::_displayTimestamp();
	std::cout << 
	"index:" << _nbAccounts << ";amount:" << _amount << ";deposits:" << _nbDeposits <<
	";withdrawals:" << _nbWithdrawals << std::endl;
	_nbAccounts++;

	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0 
}

void	Account::makeDeposit( int deposit )
{
	if(_nbAccounts == 8)
		_nbAccounts = 0;

	_nbDeposits++;
	int p_amount = _amount + deposit;

	// Account::_displayTimestamp();
	std::cout << 
	"index:" << _nbAccounts << ";p_amount:" << _amount << ";deposit:" << deposit <<
	";amount:" << p_amount << ";nb_deposits:" << _nbDeposits
	<< std::endl;

	_nbAccounts++;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += _amount;


	// std::cout << "makeDeposit" <<  std::endl <<  std::endl;

	// [19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
}

bool	Account::makeWithdrawal( int withdrawal )
{

	if(_nbAccounts == 8)
		_nbAccounts = 0;	

	int p_amount = -1;

	if(_amount - withdrawal >= 0)
		p_amount = _amount - withdrawal;

	// Account::_displayTimestamp();
	std::cout << 
	"index:" << _nbAccounts << ";p_amount:" << _amount << ";withdrawal:" ;

	if ( p_amount == -1 )
	{
		std::cout << "refused" << std::endl;
		_nbAccounts++;
		_totalAmount += _amount;
		return(0);
	}

	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" <<  p_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount = p_amount;
	_totalNbWithdrawals++;
	_nbAccounts++;
	_totalAmount += p_amount;

	// std::cout << "makeWithdrawal" <<  std::endl <<  std::endl;

	// [19920104_091532] index:0;p_amount:47;withdrawal:refused
	// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1	
	return(2);
};

// void Account::_displayTimestamp(void)
// {
//     std::time_t now = std::time(NULL);           // get current time
//     std::tm *ltm = std::localtime(&now);         // convert to local time

//     char buffer[20];
//     std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);

//     std::cout << buffer;
// }


Account::~Account( void ) //destructor 
{

	if(_nbAccounts == 8)
	{
		_nbAccounts = 0;
	}

		// Account::_displayTimestamp();
		std::cout << "index:" << _nbAccounts << ";amount:" << _amount << ";closed" << std::endl;

		_nbAccounts++;


	// [19920104_091532] index:0;amount:47;closed
}


/* 
------status--------

-> know how display what  ~~~~~

// learn 
	-Static variables & functions
	 -> why i should and i must to use static member variable inside the static member function
	 -> whyy we cant use static variable outside the class ?? 
	 -> is static always should be private ?? no
	 -> is to use a static variable we should to assigne it to static function only (no norml variables) ? no 
	 -> declaration and definition static variable 
	 -> why the definition should be inside .cpp ? (because we can have multi definition of the variable)
	 -> static variable also named [class variable]
	 -> how to access static variable and functions
	 -> static function can only access static varibale , instead of normal function can access static and non-static variables
	 -> why static function (They cannot access non-static members unless they receive an object reference.)
	-const member functions 
	-Initialization list
	-diconstructor


Constructor → yzid _nbAccounts, y3ti index, yzid l-total...
Destructor → ytprint status
makeDeposit() → yzid l-amount, yzid l-total, yzid _nbDeposits
makeWithdrawal() → yn9s l-amount ila kaffi, y3ti false ila la
displayStatus() → yprint info dyal account
displayAccountsInfos() → yprint info dyal kol accounts
*/