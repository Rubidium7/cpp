/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:40:13 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 18:44:37 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "constructed [Dog]" << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "copy constructed [Dog]" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "destructed [Dog]" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "[Dog] woof woof howl < Dog sounds" << std::endl;
}
