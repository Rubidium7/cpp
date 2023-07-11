/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:51:13 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/11 12:53:51 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{	
	DiamondTrap	mutsis("mutsis");
	mutsis.whoAmI();
	mutsis.highFivesGuys();
	mutsis.guardGate();
	mutsis.printInfo();
	mutsis.attack("faijas");
	return (0);
}
