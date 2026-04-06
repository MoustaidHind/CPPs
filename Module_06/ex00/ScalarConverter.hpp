#ifndef SCALARCONVERTER_hpp
#define SCALARCONVERTER_hpp

#include <iostream>
#include <cstdlib>
#include <stdlib.h> // should not still
#include <iomanip>
#include <limits.h>

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