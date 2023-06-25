/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:31:06 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/25 17:56:19 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string	&Weapon::getType()
{
	return (type);
}
