/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:55:32 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 21:38:29 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();	

	delete j;
	delete i;

	int	ar_size = 8;

	if (ar_size < 2)
		return (1);
	Animal *animal_array[ar_size];
	for (int i = 0; i != ar_size; i++)
	{
		if (i < ar_size / 2)
			animal_array[i] = new Dog();
		else
			animal_array[i] = new Cat();
	}
	Dog	*tmp = new Dog();
	Cat	*tmp2 = new Cat();

	tmp->getBrain().fillHeadWithIdeas("bad idea");
	tmp2->getBrain().fillHeadWithIdeas("mutsis");

	Dog	*baddie(tmp);
	baddie->getBrain().blurtOutIdeas();
	delete baddie;
	Cat *faijas;
	faijas = tmp2;
	faijas->getBrain().blurtOutIdeas();
	delete faijas;
	for (int i = 0; i != ar_size; i++)
		delete animal_array[i];
	return (0);
}
