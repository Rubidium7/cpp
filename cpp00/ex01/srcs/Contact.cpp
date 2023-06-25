

#include "Header.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void	Contact::display_field(std::string field)
{
	unsigned long	i;

	for (i = 0; i < 10 - field.length() && field.length() < 10; i++)
		std::cout << " ";
	for (i = 0; i < 9 && (field.c_str())[i]; i++)
		std::cout << (field.c_str())[i];
	if (i == 9 && (field.c_str())[i + 1])
		std::cout << ".";
	else if (i == 9 && (field.c_str())[i])
		std::cout << (field.c_str())[i];	
}

void	Contact::display_row(int row)
{
	std::cout << "        " <<  row + 1 << " |";
	display_field(first_name);
	std::cout << "|";
	display_field(last_name);
	std::cout << "|";
	display_field(nickname);
	std::cout << std::endl;
}

void	Contact::display()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

void	Contact::new_contact(std::string &first_name, std::string &last_name, 
		std::string &nickname, std::string &phone_number, std::string &secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->secret = secret;
}
