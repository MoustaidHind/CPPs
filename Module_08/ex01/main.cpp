#include "Span.hpp"

int main()
{
	{	
		try {	
			Span sp = Span(5);
			
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			// sp.addNumber(11);
			
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	
	{
		try {
			Span sp(10000);
			std::vector<int> numbers;

			for (int i = 0; i < 10000; i++) {
				numbers.push_back(i);
			}
			sp.addnumbers<std::vector<int> >(numbers.begin(), numbers.end());

			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}
