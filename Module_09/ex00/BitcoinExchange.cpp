#include "BitcoinExchange.hpp"

// OCF

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
// Copy Constructor u l-Assignment


// Parsing Database
void BitcoinExchange::loadDataBase() // DATA : (key = 2009-01-02 , value = 0)
{
	std::ifstream infile;
	std::string line;
	std::string key, value;

	infile.open("data.csv"); // should we parse that ?
	if(infile.fail()) 
	{
		std::cerr << "error opening fail !!" << std::endl;
		return;
	}

	std::getline(infile, line); // get the first line (to skip it)
	while (std::getline(infile, line)) // read line by line without (\n) 
	{
		size_t pos = line.find(',');
		if(pos != std::string::npos)
		{
			key = line.substr(0, pos);
			value = line.substr(pos + 1);

			data[key] = std::atof(value.c_str());
		}
	}
	infile.close();
}


void BitcoinExchange::printData()
{
	std::map<std::string, float>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
		std::cout << it->first << "  =>  " << it->second << std::endl;	
}

std::string trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");

	if (first == std::string::npos) // why this condition 
		return "";

    return str.substr(first, (last - first + 1));


	// should trim date first (remove spaces before the pipe line) 
	// std::string trimDate = Date;
	// size_t lastSpace = trimDate.find_last_not_of(" \t\n\r");
	// if (lastSpace != std::string::npos)
	// 	trimDate = trimDate.substr(0, lastSpace + 1);


}

bool isValidDate(const std::string &Date)
{
	// yyyy-mm-dd
	int year, month, day;
	
	std::string trimedDate = trim(Date);

	// std::cout << "-" << trimedDate << "-" << std::endl;

	size_t posY = trimedDate.find('-');
	if(posY == std::string::npos) return false;

	size_t posM = trimedDate.find('-', posY + 1);
	if(posM == std::string::npos) return false;
	
	// size_t posD = trimedDate.find(' ', posM + 1);
	// if(posD == std::string::npos) return false;

	year = std::atoi(trimedDate.substr(0, posY).c_str()); // 0 -> 4 substr(start_from, len);
	month = std::atoi(trimedDate.substr(posY + 1, posM - posY - 1).c_str()); // 5 -> 7 - 4 - 1 = 2
	day = std::atoi(trimedDate.substr(posM + 1/* , posD - posM - 1 */).c_str());

	// std::cout << "----------------------------" << std::endl;
	
	// std::cout << Date << std::endl;
	// std::cout << "YEAR : " << year << " | month : " << month << " | day : " << day << std::endl;

	// std::cout << "----------------------------" << std::endl;

	if(year < 2009 || year > 2026 || month < 1 || month > 12 || day < 1 || day > 31 || (month == 2 && (day < 1 || day > 29)))
		return false;

	return true;
}


void BitcoinExchange::calcBitoin(char *file) 
{
	std::ifstream infile;
	std::string line;

	infile.open(file); // how infile work, it store : 2011-01-03 | 2
	if(infile.fail())
	{
		std::cerr << "error opening fail !!" << std::endl;
		return;
	}

	std::getline(infile, line); // skip head
	while (std::getline(infile, line))
	{
		size_t pos = line.find('|');

		// verify pip
		if(pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// verify positive numbers
		float value = std::atof(line.substr(pos + 1).c_str());
		if(value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		else if(value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		// Date Format YYYY-MM-DD
		std::string Date = line.substr(0, pos);
		if(!isValidDate(Date))
		{
			std::cout << "Error: bad input => " << Date << std::endl;
			continue;
		}
	
		// std::cout << "m heree222." << std::endl;
		
	}
	
}

// std::cout << "LINE ---->> " << line << "///  VALUEE  ===> " << value << std::endl;

// GEMINI CHAT 
	// 1. Hèl l-Input File (av[1]) :ok
	// 2. Parse kul Line b l-Format (date | value)  :ok
	// 3. Verifyi l-Valida d l-Data (The Rules) :ok
	// 4. L-Qalib d l-Calculation (Searching the Map) (data.lower_bound(inputDate);
	// 5. L-Output l-Niha'i) =>  (2011-01-03 => 3 = 0.9).
