/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:11:43 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/25 17:54:14 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string newType);
		~Weapon();
		void				setType(std::string newType);
		const std::string	&getType(void);
	private:
		std::string			type;
};

#endif
