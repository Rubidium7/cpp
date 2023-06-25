/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:47:44 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/25 18:27:34 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name)
{}

HumanB::~HumanB()
{}

void	HumanB::attack(void)
{
	if (!weapon)
		std::cout << name << " flails their hands at you in a pathetic fashion" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &newWeapon)
{
    this->weapon = &newWeapon;
}
