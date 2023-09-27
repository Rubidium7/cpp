/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:31:25 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 15:51:02 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		~Character();

		Character &operator=(const Character &rhs);

		std::string	const	&getName() const;
		void	equip(AMateria *mat);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);

		void	printInventory() const;

	protected:
		std::string	_name;
		AMateria	*_inventory[4];
		Floor		*_floor;
};

#endif
