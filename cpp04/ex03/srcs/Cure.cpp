/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:42:57 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 16:01:59 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "constructed [Cure]" << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << "copy constructed [Cure]" << std::endl;
	*this = src;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "destructed [Cure]" << std::endl;
}

AMateria	*Cure::clone() const
{
	AMateria *ret = new Cure();
	return (ret);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
