/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:26:55 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/30 22:01:13 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"
#include <iostream>

template <typename T>
void	printer(T const &val)
{
	std::cout << val << std::endl;
}

template <typename T>
void	incrementer(T &val)
{
	val++;
}

int main()
{
	Fixed far[] = {1, 4, 5.6f, 6.9f, 10};

	std::cout << "fixed array:" << std::endl;
	iter(far, 5, printer<const Fixed>);
	std::cout << "that incremented:" << std::endl;
	iter(far, 5, incrementer<Fixed>);
    iter(far, 5, printer<const Fixed>);


	int iar[] = {0, 1, 2, 3, 4, 5};

	std::cout << "int array:" << std::endl;
	iter(iar, 6, printer<const int>);
	std::cout << "that incremented:" << std::endl;
	iter(iar, 6, incrementer<int>);
    iter(iar, 6, printer<const int>);
	return (0);
}
