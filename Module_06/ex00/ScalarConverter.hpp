#pragma once

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter(); // should i make OCF also private or just constructor ?? 

public:

	static void convert(std::string str);
};
