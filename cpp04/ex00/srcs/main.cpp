/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:32:51 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 19:24:25 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

int main()
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "cat:" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "dog:" << std::endl;
	j->makeSound();
	std::cout << "animal:" << std::endl;
	meta->makeSound();
	delete meta;
	std::cout << "copying dog to animal:" << std::endl;
	meta = j;
	meta->makeSound();

	const WrongAnimal	*mepa = new WrongAnimal();
	const WrongAnimal	*h = new WrongCat();

	std::cout << h->getType() << " " << std::endl;
	std::cout << "wrong cat:" << std::endl;
	h->makeSound(); //will not output the cat sound!
	std::cout << "wrong animal:" << std::endl;
	mepa->makeSound();

	delete j;
	delete i;
	delete mepa;
	delete h;
	return (0);
}
