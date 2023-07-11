/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:51:26 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/11 11:12:52 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &rhs);
		void	attack(const std::string &target);
		void	whoAmI();
		void	printInfo();

	private:
		std::string	_name;
};

#endif
