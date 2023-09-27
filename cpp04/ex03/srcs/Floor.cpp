/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:19:33 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 15:59:08 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : _next(nullptr), _material(nullptr)
{
	std::cout << "constructed [Floor]" << std::endl;
}

Floor::Floor(AMateria *mat) : _next(nullptr)
{
	_material = mat;
	std::cout << "constructed [Floor]" << std::endl;
}

Floor::Floor(const Floor &src) : _next(nullptr)
{
	std::cout << "copy constructed [Floor]" << std::endl;
	*this = src;
}

Floor	&Floor::operator=(const Floor &rhs)
{
	this->_next = rhs._next;
	this->_material = rhs._material;
	return (*this);
}

Floor::~Floor()
{
	if (_next)
		delete _next;
	_next = nullptr;
	delete _material;
	_material = nullptr;
	std::cout << "destructed [Floor]" << std::endl;
}

void	Floor::dropOnFloor(AMateria *mat)
{
	Floor	*tmp;

	tmp = this;
	while (tmp->_next)
		tmp = tmp->_next;
	tmp->_next = new Floor(mat);
}
