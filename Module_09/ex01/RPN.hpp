#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> stck;

public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& assign);
	~RPN();


	void calculation(const std::string &expretion);
	void simplify(char c);

};


#endif