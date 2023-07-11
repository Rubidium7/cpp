/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:55:25 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/09 18:05:48 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
   	_energy = 100;
	_dmg = 30;
	std::cout << "[FragTrap] " << _name << " enters the stage" << std::endl;
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
	std::cout << "[FragTrap] ";
	if (!_hp)
		std::cout << _name << "'s limp body is dragged off the floor" << std::endl;
	else if (_hp < 5)
		std::cout << _name << " waddles off with most of their limbs intact" << std::endl;
	else
		std::cout << _name << " walks out cheerily" << std::endl;
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
	std::cout << _name << " wants to give you a hiiiiiiiigh fiveee!" << std::endl;
}
