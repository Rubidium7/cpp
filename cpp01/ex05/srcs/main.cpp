/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:33:07 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/26 21:22:14 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string	lowercase(char *c_str)
{
	std::string	level(c_str);
	char		help;

	for (size_t i = 0; level[i]; i++)
	{
		help = tolower(level[i]);
		level[i] = help;
	}
	return (level);
}

void	print_levels(void)
{
	std::cerr << "options for levels:" << std::endl;
	std::cerr << "[DEBUG]" << std::endl;
	std::cerr << "[INFO]" << std::endl;
	std::cerr << "[WARNING]" << std::endl;
	std::cerr << "[ERROR]" << std::endl;
}

int main(int ac, char **av)
{
	std::string	level;
	Harl		harl;

	if (ac != 2 || !av[1][0])
	{
		std::cerr << "Error: arguments required" << std::endl;
		std::cerr << "input: [level]" << std::endl;
		print_levels();		
		return (37);
	}
	level = lowercase(av[1]);
	harl.complain(level);
	return (0);
}
