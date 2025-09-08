#include <iostream>
#include <string>
#include <cstdlib>  // for atoi

class Contact{

	private:
		// std::string command;
		std::string new_contact[5];

	public:
		// Contact() //default constructore 
		// {
		// 	int exitt = 1;
		// 	while (exitt)
		// 	{
		// 		std::cout << "Need to enter one of three (ADD, SEARCH or EXIT) : ";
		// 		std::getline(std::cin, command);

		// 		if(command.compare("ADD") == 0)
		// 			add();
		// 		else if(command.compare("DI") == 0)
		// 			display();
		// 		else if(command.compare("EXIT") == 0)
		// 			exitt = 0;
		// 	}
		// }

};



class PhoneBook {

	private:
		std::string arr_contact[8][5];
		std::string command;
		
		void add(int &count)
		{
			const char* info[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
			int i = 0;

			Contact con1;
			while (i < 5)
			{			
				while(arr_contact[count][i].empty())
				{
					std::cout << info[i] << " : ";
					std::getline(std::cin, arr_contact[count][i]);
				}
				i++;
			}
			count++; // handle full phonebook
		}

		void add_spaces(int nbr)
		{
			while (nbr)
			{
					std::cout << " ";
					nbr--;
			}
		}
		void display(int &count)
		{
			int i;
			int j = 0;

			std::cout << "\nindex     " << "|" \
					<<"first name" << "|" <<"last name " << "|" << "nickname  \n"<< std::endl;
			while (j < count)
			{
				i = 0;
				std::cout << j + 1 ;
				add_spaces(9);
				while(i < 3)
				{
					if(arr_contact[j][i].size() <= 10)
					{
						std::cout << "|" << arr_contact[j][i];
						add_spaces(10 - arr_contact[j][i].size());
					}
					else
					{
						std::cout << "|" << arr_contact[j][i].substr(0, 9) << ".";
					}
					i++;
				}
				std::cout << std::endl;
				j++;
			}
		}

		void search(int &count)
		{
			std::string input;
			const char* info[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
			int index = 0;
			int i = 0;

			display(count);
			if(count == 0)
				return;
			std::cout << std::endl;
			while (index < 1 || index > count)
			{
				std::cout << "Enter the index : ";
			 	std::getline(std::cin, input);
				index = atoi(input.c_str());
			}
			std::cout << "\n### All The Information ###" << std::endl;
			while(i < 5)
			{
				std::cout << info[i] << " : "<< arr_contact[index - 1][i] << std::endl;
				i++;
			}
			std::cout << std::endl;
		}

	public:
		PhoneBook()
		{
			int count = 0;
			int exitt = 1;
			while (exitt)
			{
				std::cout << "Enter one of three (ADD, SEARCH or EXIT) : ";
				std::getline(std::cin, command);

				if(command.compare("SEARCH") == 0)
				   search(count);
				else if(command.compare("ADD") == 0)
					add(count);
				else if(command.compare("EXIT") == 0)
					exitt = 0;
			}
		}
};

int main()
{
	PhoneBook book;
}

/* status 

need to :
--- This means each contact should be its own [Contact object], not just rows in a 2D array.

--- handle just 8 contacts 

--- "iomanips" in C++ 
	[Right now you’re printing then padding manually. It works, but be careful:
	 evaluation may check strict alignment. Using std::setw(10) from <iomanip> 
	 is safer and matches exactly "10 chars wide".]

- destroy new_contact array
- know which class called first
- use AI to see tests for this exercise ~~~~~~
- SEARCH methode ~~~~~
- display field's name ~~~~~
- add contacts to phonebook ~~~~

*/


// if we dont use public or private -> the default is private (methods and properties)
// getter , setter
// Constructore (one or more )
// Distractore 

// ----------------- MORE TIPS ------------------
// You put the whole input loop inside PhoneBook’s constructor.
// It works, but conceptually, constructors shouldn’t handle I/O loops. 
// The subject didn’t forbid it, but evaluators may expect the loop in main (cleaner design).