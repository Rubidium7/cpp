/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:11:20 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/08 21:34:05 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate();

	private:
};

#endif
