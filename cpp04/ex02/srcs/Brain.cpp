/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:50:31 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 20:22:33 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "constructed [Brain]" << std::endl;
	fillHeadWithIdeas("minishell");
}

Brain::Brain(const Brain &src)
{
	std::cout << "copy constructed [Brain]" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i != 100; i++)
		this->_ideas[i] = rhs._ideas[i];	
	return (*this);
}

Brain::~Brain()
{
	std::cout << "destructed [Brain]" << std::endl;
}

void	Brain::fillHeadWithIdeas(std::string thought)
{
	for (int i = 0; i != 100; i++)
		_ideas[i] = thought;
}

void	Brain::blurtOutIdeas()
{
	for (int i = 0; i != 100; i++)
		std::cout << _ideas[i] << " ";
	std::cout << std::endl;
}
