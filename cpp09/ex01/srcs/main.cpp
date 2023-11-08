/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:07:16 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/08 18:47:58 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " <expression>" << std::endl;
		return 1;
	}
	std::string input(av[1]);
	RPN			calc;

	bool fucked_up = calc.evaluateExpression(input);
	if (fucked_up)
		std::cout << "Error" << std::endl;
	return fucked_up;
}
