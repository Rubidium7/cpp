/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:51:13 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/08 21:53:32 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::srand(std::time(nullptr));

	std::cout << std::setw(46) << "*DING DING DING*" << std::endl;
	std::cout << std::setw(76);
	std::cout << "Laaaaaaadies and gentlemen are yoooou reeady for the match of a Lifetime?!" << std::endl;
	std::cout << std::setw(69);
	std::cout << "Let's give a round of applause for out greeeeat contestants!!" << std::endl << std::endl;

	std::string	c1_name = "Petteri Orpo";
	std::string	c2_name = "Riikka Purra";

	ClapTrap	c1(c1_name);
	ScavTrap	c2(c2_name);

	for (int i = 0; i != 7; i++)
	{
		std::cout << std::endl << std::setw (10) << "ROUND " << i + 1 << " GO!!" << std::endl << std::endl;
		if (std::rand() % 2)
		{
			c1.attack(c2_name);
			c2.takeDamage(c1.getDmg());
		}
		if (std::rand() % 2)
		{
			c2.attack(c1_name);
			c1.takeDamage(c2.getDmg());
		}
		if (std::rand() % 2)
			c1.beRepaired((std::rand() % 20) % 5);
		if (std::rand() % 2)
			c2.beRepaired((std::rand() % 20) % 5);
		if (std::rand() % 5)
			c2.guardGate();
	}
	return (0);
}
