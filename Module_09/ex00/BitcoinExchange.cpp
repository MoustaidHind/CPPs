#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assign) {
	if (this != &assign) {
		this->data = assign.data;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}


// Parsing Database
void BitcoinExchange::loadDataBase()
{
	std::ifstream infile;
	std::string line;
	std::string key, value;

	infile.open("data.csv");
	if(infile.fail()) 
	{
		std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
	}

	std::getline(infile, line);
	while (std::getline(infile, line))
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
	std::map<std::string, double>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
		std::cout << it->first << "  =>  " << it->second << std::endl;	
}

std::string trim(const std::string& str) 
{
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");

	if (first == std::string::npos) 
		return "";

	return str.substr(first, (last - first + 1));
}

bool isValidDate(std::string &Date)
{
	int year, month, day;
	
	Date = trim(Date);
	if(Date.size() != 10)
		return false;
	
	for (size_t i = 0; i < Date.length(); i++) {
		if (!std::isdigit(Date[i]) && Date[i] != '-') {
			return false; 
		}
	}

	size_t posY = Date.find('-');
	if(posY != 4) return false;

	size_t posM = Date.find('-', posY + 1);
	if(posM != 7) return false;
	
	year = std::atoi(Date.substr(0, posY).c_str());
	month = std::atoi(Date.substr(posY + 1, posM - posY - 1).c_str());
	day = std::atoi(Date.substr(posM + 1).c_str());

	if(year < 2009 || year > 2026 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2)
	{
		bool isLeap = ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
		if (isLeap && day > 29) return false;
		if (!isLeap && day > 28) return false;
	}

	return true;
}

bool isValidNumberFormat(const std::string& str) {
	int point = 0;
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-') 
		i++;

	if (i == str.length()) 
		return false; 

	for (; i < str.length(); i++) {
		if (str[i] == '.')
			point++;
		else if (!std::isdigit(str[i]))
			return false;
	}
	return point <= 1;
}

void BitcoinExchange::calcBitcoin(char *file) 
{
	std::ifstream infile;
	std::string line;
	bool firstLine = true;

	infile.open(file);
	if(infile.fail())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	while (std::getline(infile, line))
	{
		if (firstLine)
		{
			firstLine = false;
			if (line == "date | value")
				continue;
		}

		size_t pos = line.find('|');
		if(pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string valueStr = trim(line.substr(pos + 1));
		if (valueStr.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidNumberFormat(valueStr)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = std::atof(valueStr.c_str());
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
	
		// clculates bitcoins
		std::map<std::string, double>::iterator it = data.lower_bound(Date);	
		if (it == data.begin() && it->first != Date)
		{
			std::cout << "Error: Old Date => " << Date << std::endl;
			continue;
		}
		if (it == data.end() || it->first != Date) {
			--it; 
		}
		std::cout << Date << " => " << value << " = " << (value * it->second) << std::endl;
	}	
}