#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>


class RPN
{
private:
	std::stack<int> stck;

public:
	//ocf
	RPN();
	~RPN();


	void calculation(const std::string &expretion);
	void simplify(char c);

};


#endif