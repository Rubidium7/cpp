/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:01:47 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/08 21:49:24 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "[ClapTrap] " << _name << " enters the stage" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src._name), _hp(src._hp), _energy(src._energy), _dmg(src._dmg)
{
	std::cout << "[ClapTrap] " << _name << "'s copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] ";
	if (!_hp)
		std::cout << _name << "'s limp body is dragged off the floor" << std::endl;
	else if (_hp < 5)
		std::cout << _name << " waddles off with most of their limbs intact" << std::endl;
	else
		std::cout << _name << " walks out cheerily" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_dmg = rhs._dmg;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "[ClapTrap] ";
	if (!_hp)
		std::cout << _name << "'s dead body wobbles maliciously" << std::endl;
	else if (!_energy)
		std::cout << _name << " is too eepy to attack" << std::endl;
	else
	{
		_energy -= 1;
		std::cout << _name << " attacks [" << target << "], causing [" << _dmg << "] points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hp)
		std::cout << _name << " would take damage if they weren't DEAD you sicko" << std::endl;
	else
	{
		std::cout << _name << " takes [" << amount << "] points of damage";
		_hp -= amount;
		if (_hp <= 0)
		{
			_hp = 0;
			std::cout << " and DIES. Rest in peace buddy!";
		}
		std::cout << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energy)
		std::cout << _name << " is too exhausted to heal (don't say mood don't say mood)" << std::endl;
	else if (!_hp)
		std::cout << _name << " is not coming back" << std::endl;
	else
	{
		std::cout << _name << " repaires themself for [" << amount << "] hp" << std::endl;
		_hp += amount;
		_energy -= 1;
	}
}
