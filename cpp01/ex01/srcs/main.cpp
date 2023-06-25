/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:21:15 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/25 15:38:14 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name = "student";
	int	i;
	Zombie	*zombies = zombieHorde(10, name);

	std::cout << "memory address of zombies is: " << zombies << std::endl;
	for (i = 0; i != 10; i++)
		zombies[i].announce();
	std::cout << "amount of " << name << "s: " << i << std::endl;
	delete [] zombies;
	return (0);
}
