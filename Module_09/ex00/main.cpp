#include "BitcoinExchange.hpp"

// value of a certain amount of bitcoin on a certain date.


int main(int ac, char **av)
{
	(void) av;
	if(ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	
	BitcoinExchange btc;

	btc.loadDataBase();
	// btc.printData();

	btc.calcBitcoin(av[1]);
	// GEMINI CHAT 
	// 1. Hèl l-Input File (av[1])
	// 2. Parse kul Line b l-Format (date | value) 
	// 3. Verifyi l-Valida d l-Data (The Rules)
	// 4. L-Qalib d l-Calculation (Searching the Map) (data.lower_bound(inputDate);
	// 5. L-Output l-Niha'i) =>  (2011-01-03 => 3 = 0.9).


	return 0;
}



// You need to load the data.csv first into your map, then open av[1] and parse it.

/* 
$> ./btc input.txt

2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
*/

/* 

still one problem 0.32 instead of 0.32
handle some cases

*/