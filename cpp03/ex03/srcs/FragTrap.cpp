/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:55:25 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/11 12:55:05 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name, int hp, unsigned int energy, unsigned int dmg) : ClapTrap(name)
{
	_hp = hp;
	_energy = energy;
	_dmg = dmg;
	std::cout << "[FragTrap] " << _name << " created" << std::endl;
}

FragTrap::FragTrap(std::string name, int hp, unsigned int dmg) : ClapTrap(name)
{
	_hp = hp;
	_dmg = dmg;
	std::cout << "[FragTrap] " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src._name)
{
	*this = src;
	std::cout << "[FragTrap] " << _name << "'s copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_dmg = rhs._dmg;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << _name << " destroyed" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << "[FragTrap] ";
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

void	FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] " << _name << " wants to give you a hiiiiiiiigh fiveee!" << std::endl;
}
