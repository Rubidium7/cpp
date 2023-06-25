/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:51:13 by nlonka            #+#    #+#             */
/*   Updated: 2023/06/25 21:33:00 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::srand(std::time(nullptr));

	std::cout << std::setw(46) << "*DING DING DING*" << std::endl;
	std::cout << std::setw(76);
	std::cout << "Laaaaaaadies and gentlemen are yoooou reeady for the match of a Lifetime?!" << std::endl;
	std::cout << std::setw(69);
	std::cout << "Let's give a round of applause for out greeeeat contestants!!" << std::endl << std::endl;

	ClapTrap	Dimitri("Dima");
	ClapTrap	Pm("Petteri Orpo");

	for (int i = 0; i != 7; i++)
	{
		std::cout << std::endl << std::setw (10) << "ROUND " << i + 1 << " GO!!" << std::endl << std::endl;
		Dimitri.attack("Petteri Orpo");
		Pm.attack("Dimmu");
		std::cout << "A random gust of wind hits them both in the face:" << std::endl;
		Dimitri.takeDamage((std::rand() % 20) % 5);
		Pm.takeDamage((std::rand() % 20) % 5);
		if (std::rand() % 2)
			Dimitri.beRepaired((std::rand() % 20) % 5);
		if (std::rand() % 2)
			Pm.beRepaired((std::rand() % 20) % 5);
	}
	return (0);
}
