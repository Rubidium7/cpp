/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:58:05 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 19:18:05 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Cat.hpp"

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &rhs);
		void		makeSound() const;
		std::string	getType() const;

	protected:
		std::string	_type;
};

#endif
