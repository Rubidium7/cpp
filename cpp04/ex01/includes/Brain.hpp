/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:49:18 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 20:20:59 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain &operator=(const Brain &rhs);
		
		void	fillHeadWithIdeas(std::string thought);
		void	blurtOutIdeas();

	private:
		std::string	_ideas[100];
};

#endif
