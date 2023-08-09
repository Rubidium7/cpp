/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:07:39 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/05 17:41:02 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_brain = new Brain();
	_type = "Cat";
	std::cout << "constructed [Cat]" << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "copy constructed [Cat]" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	this->_brain = rhs._brain;
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "destructed [Cat]" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "[Cat] mew mew I'm a cat" << std::endl;
}

Brain	&Cat::getBrain()
{
	return (*_brain);
}

std::string	Cat::getType() const
{
	return (_type);
}
