/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:31:58 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 16:09:02 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "Cure.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"
# include <iostream>

int main()
{
	std::cout << "the test from the subject:" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;

	std::cout << std::endl << "testing a full inventory and copying:" << std::endl;

	Character	*mutsis = new Character("mutsis");

	for (int i = 0; i != 6; i++)
	{
		if (i % 2)
			tmp = src->createMateria("ice");
		else
			tmp = src->createMateria("cure");
		mutsis->equip(tmp);
		if (i > 3)
			delete tmp;
	}
	std::cout << "mutsis' inventory:" << std::endl;
	mutsis->printInventory();
	Character	*faijas = new Character(*mutsis);

	mutsis->unequip(1);
	mutsis->unequip(3);
	std::cout << "mutsis' inventory after unequipping:" << std::endl;
	mutsis->printInventory();
	std::cout << "faijas' inventory:" << std::endl;
	faijas->printInventory();
	delete mutsis;
	delete faijas;
	delete src;
	return (0);
}
