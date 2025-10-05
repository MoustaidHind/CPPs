#include "phonebook.hpp"


void PhoneBook::add(int &count)
{
	{
		if(count >= 8)
			contacts[count % 8].reset_contact();
		contacts[count % 8].setFirstName();
		contacts[count % 8].setLastName();
		contacts[count % 8].setNickname();
		contacts[count % 8].setPhoneNumber();
		contacts[count % 8].setDarkestSecret();
		count++; // handle full phonebook
	}
}


void PhoneBook::search(int &count)
{
	std::string input;
	const char* info[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	int index = 0;

	display(count);
	if(count == 0)
		return;
	std::cout << std::endl;
	while (index < 1 || index > std::min(count, 8)) // min() in case count greater then 8  
	{
		std::cout << "Enter the correct index : ";
		if(!std::getline(std::cin, input))
			exit(-1);
		index = atoi(input.c_str());
	}
	std::cout << "\n### All The Information ###" << std::endl;

	std::cout << std::setw(17) << std::left << info[0] << " : "<< contacts[index - 1].getFirstName() << std::endl;
	std::cout << std::setw(17) << info[1] << " : "<< contacts[index - 1].getLastName() << std::endl;
	std::cout << std::setw(17) << info[2] << " : "<< contacts[index - 1].getNickname() << std::endl;
	std::cout << std::setw(17) << info[3] << " : "<< contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << std::setw(17) << info[4] << " : "<< contacts[index - 1].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}


void PhoneBook::line()
{
	for(int i = 0; i < 4; i++)
	{
		std::cout << std::setfill('-') << std::setw(11) << "+";
	}
	std::cout << std::endl;
	std::cout << std::setfill(' '); //to reset with space
}


void PhoneBook::display(int &count)
{
	int j = 0;
	int rows;

	if(count == 0)
	{
		std::cout << "### YOU SHOULD ADD AT LEAST ONE CONTACT ###" << std::endl;
		return;
	};
	if(count >= 8)
		rows = 8;
	else
		rows = count;
	line();
	std::cout << std::setw(10) << std::right << "index" << "|" 
		<< std::setw(10) <<"first name" << "|"
		<< std::setw(10) <<"last name" << "|" 
		<< std::setw(10) << "nickname" << std::endl;
	line();
	while (j < rows)
	{
		std::cout << std::setw(10) << j + 1 ;

		if(contacts[j].getFirstName().size() <= 10)
			std::cout << "|" << std::setw(10) << contacts[j].getFirstName();
		else
			std::cout << "|" << contacts[j].getFirstName().substr(0, 9) << ".";

		if(contacts[j].getLastName().size() <= 10)
			std::cout << "|" << std::setw(10) << contacts[j].getLastName();
		else
			std::cout << "|" << contacts[j].getLastName().substr(0, 9) << ".";

		if(contacts[j].getNickname().size() <= 10)
			std::cout << "|" << std::setw(10) << contacts[j].getNickname();
		else
			std::cout << "|" << contacts[j].getNickname().substr(0, 9) << ".";
		std::cout << std::endl;
		line();
		j++;
	}
}