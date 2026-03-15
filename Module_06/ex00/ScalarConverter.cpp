#include "ScalarConverter.hpp"



// output its value in the following series of scalar types:
// • char
// • int
// • float
// • double

// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

// like strtol or strtod
// function that can convert from str to other , give the resource of it 

void ScalarConverter::convert(std::string str)
{

	std::cout << "literal string : " << str << std::endl;
	std::cout << static_cast<char>(str) << std::endl;
	std::cout << static_cast<int>(str) << std::endl;
	std::cout << static_cast<float>(str) << std::endl;
	std::cout << static_cast<double>(str) << std::endl;



}