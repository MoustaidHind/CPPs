#include "phonebook.hpp"

void Contact::reset_contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}


void Contact::add_field(std::string &field, std::string text)
{
	{
		while(field.empty())
		{
			std::cout << text << " : " ;
			if(!std::getline(std::cin, field))
				exit(-1);
		}
	}
}


void Contact::setFirstName(){ 
	add_field(first_name, "first name");
}
std::string Contact::getFirstName(){
	return(first_name);
}


void Contact::setLastName(){
	add_field(last_name, "last name");
}
std::string Contact::getLastName(){
	return(last_name);
}


void Contact::setNickname(){
	add_field(nickname, "nickname");
}
std::string Contact::getNickname(){
	return(nickname);
}


void Contact::setPhoneNumber(){
	add_field(phone_number, "phone number");
}
std::string Contact::getPhoneNumber(){
	return(phone_number);
}


void Contact::setDarkestSecret(){
	add_field(darkest_secret, "darkest secret");
}
std::string Contact::getDarkestSecret(){
	return(darkest_secret);
}
