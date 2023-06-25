/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:22:24 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/26 21:31:59 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamEditor.hpp"

int	errawr_message(int var)
{
	std::cerr << "Errawr 🦖" << std::endl;
	if (var)
	{
		std::cerr << "to str to replace cannot be empty sowwy" << std::endl;
		return (69);
	}
	std::cerr << "argument format should be:" << std::endl;
	std::cerr << "[filename] [str to replace] [replacing str]" << std::endl;
	return (37);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (errawr_message(0));
	if (!av[2][0])
		return (errawr_message(1));
	std::string	filename(av[1]);
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	StreamEditor	sedder(filename, s1, s2);
	sedder.you_sed_it_bestie();
	return (0);
}
