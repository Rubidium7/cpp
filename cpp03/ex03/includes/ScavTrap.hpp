/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:11:20 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/11 11:17:22 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name, int hp, unsigned int energy, unsigned int dmg);
		ScavTrap(std::string name, unsigned int energy);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif
