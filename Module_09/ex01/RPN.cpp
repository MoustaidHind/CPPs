#include "RPN.hpp"



RPN::RPN()
{
}

RPN::~RPN()
{
}

int is_operators(char c)
{
	// std::cout << c << std::endl;
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

void RPN::simplify(char c)
{
	int a, b;

	a = stck.top();
	stck.pop();
	
	b = stck.top();
	stck.pop();

	std::cerr << "do operation  " << a << c << b << std::endl;
	
	if(c == '*')
		stck.push(b * a);
	else if(c == '+')
		stck.push(b + a);
	else if(c == '-')
		stck.push(b - a);
	else if(c == '/')
		stck.push(b / a);

	std::cerr << "top on stack  " << stck.top() << std::endl;
	
}

void RPN::calculation(const std::string &expre)
{
	int i = 0;
	while (expre[i])
	{
		if (expre[i] == ' ') {
			std::cerr << "skip space" << std::endl;
			i++; // hiyyed l-space u chouf l-character li murah
			continue;
		}

		// -> check between 0-9 
		if(expre[i] < '0' || expre[i] > '9')
		{
			if(is_operators(expre[i]))
			{
				std::cerr << "find opratore  " << expre[i] << std::endl;

				simplify(expre[i]);
		std::cerr << "simplifieddd -------" << std::endl;

				i++;
				continue;
			}
			std::cerr << "Error\n" << std::endl;
			return ;
		}
		
		stck.push(expre[i] - '0');
		std::cerr << "find numbeer  " << stck.top() << std::endl;

		i++;
	}
	

	while (!stck.empty())
	{
		std::cout << stck.top() << "|" ;
		stck.pop();
	}
	std::cout << std::endl;


	// parssing 
	/* 
	*/

	// 

}
