/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:27:18 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/03 15:56:17 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	check_spaces(char **av, int i)
{
	if (!av[i + 1]) 
		return (0);
	if (av[i + 1][0] == ' ')
		return (0);
	for (int i2 = 0; av[i][i2]; i2++)
	{
		if (!av[i][i2 + 1] && av[i][i2] == ' ')
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	char	c;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int i2 = 0; av[i][i2]; i2++)
			{
				c = toupper(av[i][i2]);
				std::cout << c;
			}
			if (check_spaces(av, i))
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
