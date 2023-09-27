/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:28 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 16:11:04 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i != 4; i++)
		_recipes[i] = nullptr;
	std::cout << "constructed [MateriaSource]" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "copy constructed [MateriaSource]" << std::endl;
	*this = src;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i != 4; i++)
	{
		if (this->_recipes[i])
			delete this->_recipes[i];
		this->_recipes[i] = nullptr;
	}
	for (int i = 0; i != 4; i++)
	{
		if (rhs._recipes[i])
			this->_recipes[i] = rhs._recipes[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i != 4; i++)
	{
		if (_recipes[i])
			delete _recipes[i];
	}
	std::cout << "destructed [MateriaSource]" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *mat)
{
	if (!mat)
	{
		std::cout << "can't learn NULL materia" << std::endl;
		return ;
	}
	for (int i = 0; i != 4; i++)
	{
		if (!_recipes[i])
		{
			_recipes[i] = mat;
			std::cout << "learned " << mat->getType() << " materia" << std::endl;
			return ;
		}
	}
	std::cout << "couldn't learn " << mat->getType() << " materia, because recipebook is FULL" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i != 4; i++)
	{
		if (_recipes[i] && _recipes[i]->getType() == type)
		{
			std::cout << "created " << type << " materia from recipes" << std::endl;
			return (_recipes[i]->clone());
		}
	}
	std::cout << type << " didn't match any recipes" << std::endl;
	return (0);
}
