#ifndef SCALARCONVERTER_hpp
#define SCALARCONVERTER_hpp

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

public:
	static void convert(const std::string& str);
};

#endif