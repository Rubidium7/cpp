/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:16:29 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 20:02:17 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal &src);
		virtual ~Animal();

		Animal &operator=(const Animal &rhs);
		virtual void	makeSound() const;
		std::string		getType() const;

	protected:
		std::string	_type;
};

#endif
