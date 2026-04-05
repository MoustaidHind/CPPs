#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str)
{
	double value;
	char *endptr;
	int checkNan = 0;

	if(str.length() == 1 && !std::isdigit(str[0])) // a, *, Z ...
	{
		char chr = str[0];
		std::cout << "char: '" << chr << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(chr) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(chr) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(chr) << std::endl;
		return;
	}

	// check nan, nanf
	if(str == "nan" || str == "nanf" )
		checkNan = 1;
	
	value = strtod(str.c_str(), &endptr);

	if( str.empty() || (!(*endptr == '\0' || (*endptr == 'f' && *(endptr+1) == '\0'))) ) // "", 13fe
	{
		std::cout << "Error: invalid literal input !" << std::endl; 
		return;
	}

	if(value < 0 || value > 127 || checkNan) // -5, 130 || nan, nanf
		std::cout << "char: impossible" << std::endl;
	else if(value == 0 || value <= 31 || value == 127) // 0, 500, 600 ...
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	
	if(checkNan || value > INT_MAX || value < INT_MIN) // nan. nanf
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	
	if(static_cast<int>(value) == value) // 33 == 33.5
		std::cout << std::fixed << std::setprecision(1); // 33 == 33 do 33.0

	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: "  << value << std::endl;
}

// check my code with ai