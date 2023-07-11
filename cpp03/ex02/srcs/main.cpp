/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:51:13 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/09 18:06:58 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::srand(std::time(nullptr));

	std::cout << std::setw(46) << "*DING DING DING*" << std::endl;
	std::cout << std::setw(76);
	std::cout << "Laaaaaaadies and gentlemen are yoooou reeady for the match of a Lifetime?!" << std::endl;
	std::cout << std::setw(69);
	std::cout << "Let's give a round of applause for out greeeeat contestants!!" << std::endl << std::endl;

	std::string	c1_name = "Vilhelm Junnila";
	std::string	c2_name = "Facebook";

	FragTrap	c1(c1_name);
	FragTrap	c2(c2_name);

	c1.highFivesGuys();
	c1.attack(c2_name);
	c2.takeDamage(c1.getDmg());
	c2.beRepaired(c1.getDmg());
	for (int i = 0; i != 4; i++)
	{
		c2.attack(c1_name);
		if (c2.getEnergy() && c2.getHp())
			c1.takeDamage(c2.getDmg());
		c1.beRepaired(std::rand() % 14);
	}
	return (0);
}
