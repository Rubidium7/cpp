/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:36:05 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/08 21:39:04 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
   	_energy = 50;
	_dmg = 20;
	std::cout << "[ScavTrap] " << _name << " enters the stage" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src._name)
{
	*this = src;
	std::cout << "[ScavTrap] " << _name << "'s copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_dmg = rhs._dmg;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] ";
	if (!_hp)
		std::cout << _name << "'s limp body is dragged off the floor" << std::endl;
	else if (_hp < 5)
		std::cout << _name << " waddles off with most of their limbs intact" << std::endl;
	else
		std::cout << _name << " walks out cheerily" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "[ScavTrap] ";
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

void	ScavTrap::guardGate()
{
	std::cout << _name << " is now gatekeeping" << std::endl;
}
