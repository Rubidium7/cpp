/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:56:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/07/09 18:07:48 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &rhs);

		void	attack(const std::string &target);
		void	highFivesGuys();
};

#endif
