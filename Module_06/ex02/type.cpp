
#include "type.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>


Base* generate(void)
{
	int rnd = std::rand() % 3;
	if (rnd == 0)
		return (new A);
	else if(rnd == 1)
		return(new B);
	return(new C);
}


void identify(Base* p)
{
	if( dynamic_cast<A*>(p) )
		std::cout << "Derived class is A" << std::endl;
	else if( dynamic_cast<B*>(p) )
		std::cout << "Derived class is B" << std::endl;
	else if( dynamic_cast<C*>(p) )
		std::cout << "Derived class is C" << std::endl;
	else
		std::cout << "\nError: Unknown derived class" << std::endl;
}


void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Derived class is A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Derived class is B" << std::endl;
			return;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Derived class is C" << std::endl;
				return;
			}
			catch(const std::exception& e)
			{
				std::cout << "\nError: Unknown derived class" << std::endl;
			}
		}
	}
}

