#include "BitcoinExchange.hpp"

#include <map>
#include <fstream>
#include <sstream> 
#include <string>  
// value of a certain amount of bitcoin on a certain date.


int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	std::map<std::string, float> data;
	std::ifstream infile;
	std::string line;
	std::string key_val;

	infile.open(av[1]);
	if(infile.fail())
	{
		std::cerr << "error opening fail !!" << std::endl;
		return 1;
	}


	std::getline(infile, line); // get the first line (to skip it)
	while (std::getline(infile, line)) // read line by line without (\n) 
	{
		std::stringstream ss(line); 
		while (std::getline(ss, key_val, ',')) // why we dont pass line direct ?
		{
			std::cout << key_val << std::endl;

		}
	}
	
	infile.close();
	return 0;
}

// 1. The Database vs. The Input File