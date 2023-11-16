/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:16:51 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/16 18:46:16 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " <input_file>" << std::endl;
		return (1);
	}
	std::string	infile(av[1]);
	try {
		BitcoinExchange btc(infile, "data.csv");
		btc.printRates();
	}
	catch (std::exception &e) {
		return (2);
	}
	return (0);
}
