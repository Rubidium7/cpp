/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:59:24 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 15:55:41 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _floor(nullptr)
{
	_name = "John Doe";
	for (int i = 0; i != 4; i++)
		_inventory[i] = nullptr;
	std::cout << "constructed [Character]" << std::endl;
}

Character::Character(std::string name) : _floor(nullptr)
{
	_name = name;
	for (int i = 0; i != 4; i++)
		_inventory[i] = nullptr;
	std::cout << "constructed [Character]" << std::endl;
}

Character::Character(const Character &src) : _floor(nullptr)
{
	std::cout << "copy constructed [Character]" << std::endl;
	for (int i = 0; i != 4; i++)
		_inventory[i] = nullptr;
	*this = src;
}

Character	&Character::operator=(const Character &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	for (int i = 0; i != 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
	}
	for (int i = 0; i != 4; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	if (_floor)
		delete _floor;
	for (int i = 0; i != 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "destructed [Character]" << std::endl;
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::printInventory() const
{
	for (int i = 0; i != 4; i++)
	{
		if (_inventory[i])
			std::cout << "Slot[" << i << "] " << _inventory[i]->getType() << std::endl;
	}
}

void	Character::equip(AMateria *mat)
{
	if (!mat)
	{
		std::cout << "[NULL] materia can't be equipped" << std::endl;
		return ;
	}
	for (int i = 0; i != 4; i++)
	{
		if (_inventory[i] && i == 3)
		{
			std::cout << _name << "'s inventory is full" << std::endl;
			return ;
		}
		if (!_inventory[i])
		{
			_inventory[i] = mat;
			std::cout << _name << " equipped " << mat->getType();
			std::cout << " at inventory slot [" << i << "]" << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (!_inventory[idx])
	{
		std::cout << "Nothing at " << _name << "'s inventory slot [" << idx << "] to be unequipped" << std::endl;
		return ;
	}
	if (!_floor)
		_floor = new Floor(_inventory[idx]);
	else
		_floor->dropOnFloor(_inventory[idx]);
	std::cout << _name << " dropped " << _inventory[idx]->getType() << " on the floor" << std::endl;
	_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter &target)
{
	if (!_inventory[idx])
		std::cout << _name << ": uses uhh absolutely nothing" << std::endl;
	else
		_inventory[idx]->use(target);
}
