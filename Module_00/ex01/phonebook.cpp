#include "phonebook.hpp"


int main()
{
	PhoneBook book;
	std::string command;

	int count = 0;
	int exitt = 1;
	while (exitt )
	{
		std::cout << "Enter one of three (ADD, SEARCH or EXIT) : ";
		std::getline(std::cin, command);

		if(command.compare("ADD") == 0)
			book.add(count);
		else if(command.compare("SEARCH") == 0)
		   book.search(count);
		else if(command.compare("EXIT") == 0 || std::cin.eof()) // check thaat to dont crash 
			exitt = 0;
	}

}

/* status 

- is required to handle eof

*/