
#include "Header.hpp"

PhoneBook::PhoneBook() : index(0), biggest(0), exist(0)
{}

PhoneBook::~PhoneBook()
{}

int		PhoneBook::check_val(std::string &first_name, std::string &last_name, 
		std::string &nickname, std::string &phone_number, std::string &secret)
{
	if (!first_name.c_str() || !last_name.c_str() || !nickname.c_str()
			|| !phone_number.c_str() || !secret.c_str())
		return (1);
	if (!first_name.length())
		return (1);
	if (!last_name.length())
		return (1);
	if (!nickname.length())
		return (1);
	if (!phone_number.length())
		return (1);
	if (!secret.length())
		return (1);
	return (0);
}

void	PhoneBook::add()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;

	std::cout << "First name:" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "Last name:" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Phone number:" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "Your darkest secret:" << std::endl;
	std::getline(std::cin, secret);
	if (check_val(first_name, last_name, nickname, phone_number, secret))
	{
		std::cout << "field incorrect" << std::endl;
		return ;
	}
	this->contact[index].new_contact(first_name, last_name, 
			nickname, phone_number, secret);
	if (biggest < index)
		biggest = index;
	index++;
	exist = 1;
	if (index >= 8)
		index = 0;
	std::cout << "add successful 😎" << std::endl;
}

void	PhoneBook::search()
{	
	int			field;
	std::string	buf;

	if (!exist)
	{
		std::cout << "lol you have no contacts loser 🦖" << std::endl;
		return ;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "  index   |first name|last name | nickname " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	for (field = 0; field <= biggest; field++)
	{
		this->contact[field].display_row(field);
		if (field + 1 <= biggest)
			std::cout << "----------|----------|----------|----------" << std::endl;	
	}
	std::cout << "-------------------------------------------" << std::endl;
	while (1)
	{	
		std::cout << "Choose index:" << std::endl;
		if (!std::getline(std::cin, buf))
			return ;
		field = atoi(buf.c_str());
		if (buf.length() != 1 || field - 1 < 0 || field - 1 > biggest)
		{
			std::cout << "incorrect field >:(" << std::endl;
			continue ;
		}
		this->contact[field - 1].display();
		std::cout << "search successful :) <3" << std::endl;
		break ;
	}
}
