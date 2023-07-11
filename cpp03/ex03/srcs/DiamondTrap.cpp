/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:05:17 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/11 12:54:25 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name, 50), FragTrap(name, 100, 30), _name(name)
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_dmg = FragTrap::_dmg;
	std::cout << "[DiamondTrap] " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src._name + "_clap_name"), 
	ScavTrap(src._name, 100, 50, 20), 
	FragTrap(src._name, 100, 100, 30),
	_name(src._name)
{
	_hp = src._hp;
	_energy = src._energy;
	_dmg = src._dmg;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " << _name << " destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_dmg = rhs._dmg;
	return (*this);
}

void	DiamondTrap::attack(const std::string &name)
{
	ScavTrap::attack(name);
}

void	DiamondTrap::printInfo()
{
	std::cout << "My, " << _name << "'s, attributes are:" << std::endl;
	std::cout << "health[" << _hp << "]" << std::endl;
	std::cout << "energy[" << _energy << "]" << std::endl;
	std::cout << "damage[" << _dmg << "]" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Oh " << ClapTrap::_name << " was my father's name. ";
	std::cout << "Call me " << _name << std::endl;
}
