#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) {	*this = copy; }

RPN& RPN::operator=(const RPN& src)
{
	if (this != &src) {
		this->stck = src.stck;
	}
	return *this;
}
int is_operators(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

void RPN::simplify(char c)
{
	int a, b;

	if(stck.size() < 2)
	{
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}

	a = stck.top();
	stck.pop();
	
	b = stck.top();
	stck.pop();

	if(c == '*')
		stck.push(b * a);
	else if(c == '+')
		stck.push(b + a);
	else if(c == '-')
		stck.push(b - a);
	else if(c == '/')
	{
		if(a == 0)
		{
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
		stck.push(b / a);
	}	
}

void RPN::calculation(const std::string &expre)
{
	int i = 0;
	while (expre[i])
	{
		if (expre[i] == ' ') {
			i++;
			continue;
		}

		if (expre[i + 1] != ' ' && expre[i + 1] != '\0') {
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}

		if(expre[i] < '0' || expre[i] > '9')
		{
			if(is_operators(expre[i]))
			{
				simplify(expre[i]);
				i++;
				continue;
			}
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
		
		stck.push(expre[i] - '0');
		i++;
	}
	
	if(stck.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}
	std::cout << stck.top() << std::endl;
}
