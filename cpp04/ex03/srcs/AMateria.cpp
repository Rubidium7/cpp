/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:59:32 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 16:10:56 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = nullptr;
	std::cout << "constructed [AMateria]" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
	std::cout << "constructed [AMateria]" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "copy constructed [AMateria]" << std::endl;
	*this = src;
}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "destructed [AMateria]" << std::endl;
}

std::string	const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "used generic materia on " << target.getName() << std::endl;
}
