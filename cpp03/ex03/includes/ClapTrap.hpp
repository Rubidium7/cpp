/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:43:26 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/11 10:45:38 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap	&src);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &rhs);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		unsigned int	getDmg();
		unsigned int	getHp();
		unsigned int	getEnergy();
		void			printInfo();

	protected:
		std::string		_name;
		int				_hp;
		unsigned int	_energy;
		unsigned int	_dmg;
};

#endif
