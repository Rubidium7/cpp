/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:25:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 21:22:29 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Dog.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();

		Cat &operator=(const Cat &rhs);
		void	makeSound() const;
		Brain	&getBrain();

	private:
		Brain	*_brain;
};

#endif
