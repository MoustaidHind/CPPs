#include<iostream>

int main()
{

	int x;
	int *d;

	int &ref = x;
	d = &x;

	std::cout << "ref = " << &ref << std::endl;
	std::cout << "x = " << &x << std::endl;
	std::cout << "d = " << &d << std::endl;
}