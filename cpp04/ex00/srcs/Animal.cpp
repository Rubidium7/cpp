/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:32:17 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 19:00:45 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "constructed [Animal]" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "copy constructed [Animal]" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	_type = rhs._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "destructed [Animal]" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "[Animal] an appropriate animal sound" << std::endl;
}
