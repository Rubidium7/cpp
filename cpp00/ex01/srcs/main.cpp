/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:56:28 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/15 17:52:37 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string buf;

	std::cout << "WELCOME TO THE BEST PHONEBOOK" << std::endl;
	std::cout << "you can use such great commands as ADD, SEARCH or EXIT" << std::endl;
	while (37)
	{
		if (!std::getline(std::cin, buf))
			break ;
		else if (buf == "EXIT")
			break ;
		else if (buf == "ADD")
			phonebook.add();
		else if (buf == "SEARCH")
			phonebook.search();
		else if (buf.length() > 0)
			std::cout << "git gud n00b🦖" << std::endl;
	}
    std::cout << "Byee!!🦕" << std::endl;
	return (0);
}
