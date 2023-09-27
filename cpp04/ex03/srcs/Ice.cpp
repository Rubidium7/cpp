/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:14:08 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 16:02:21 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "constructed [Ice]" << std::endl;
}

Ice::Ice(const Ice &src)
{
	std::cout << "copy constructed [Ice]" << std::endl;
	*this = src;
}

Ice	&Ice::operator=(const Ice &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "destructed [Ice]" << std::endl;
}

AMateria	*Ice::clone() const
{
	AMateria *ret = new Ice();
	return (ret);
}

void	Ice::use(ICharacter	&target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
