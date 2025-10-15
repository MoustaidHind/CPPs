#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip> 

class Contact{

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact() {};

		void reset_contact();

		void add_field(std::string &field, std::string text);

		void setFirstName();
		std::string getFirstName();

		void setLastName();
		std::string getLastName();

		void setNickname();
		std::string getNickname();

		void setPhoneNumber();
		std::string getPhoneNumber();

		void setDarkestSecret();
		std::string getDarkestSecret();
};


class PhoneBook {

	private:
		Contact contacts[8];
		
	public:
		PhoneBook(){};
		void line();
		void display(int &count);
		void add(int &count);
		void search(int &count);
};

#endif