/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:16:29 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/11 15:44:42 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

class Floor
{
	public:
		Floor();
		Floor(AMateria *mat);
		Floor(const Floor &src);
		~Floor();

		Floor &operator=(const Floor &rhs);
		
		void	dropOnFloor(AMateria *mat);

	private:
		Floor		*_next;
		AMateria	*_material;
};

#endif
