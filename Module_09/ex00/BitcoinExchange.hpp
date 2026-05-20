#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE


#include <map>
#include <fstream>
#include <sstream> 
#include <string> 
#include <cstdlib> // atof

#include <iostream>


class BitcoinExchange
{
private:
	std::map<std::string, float> data;
	
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();



	void loadDataBase();
	void printData();
	void calcBitoin(char *file);

};




#endif
