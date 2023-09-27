/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:59:19 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 19:17:47 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "constructed [WrongAnimal]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "copy constructed [WrongAnimal]" << std::endl;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "destructed [WrongAnimal]" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] an inappropriate animal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
