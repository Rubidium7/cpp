/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:39:03 by nlonka            #+#    #+#             */
/*   Updated: 2023/06/15 16:22:50 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(4.521f) / Fixed(34.3f));

	std::cout << "incrementations with a:" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "a wild b appears:" << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "more messing around with a:" << std::endl;
	a = a * 4;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	
	std::cout << Fixed::min(a, --a) << std::endl;

	std::cout << "wait till you c this:" << std::endl;
	std::cout << c << std::endl;
	std::cout << a << std::endl;
	std::cout << c / a << std::endl;
	std::cout << (c > a) << std::endl;
	std::cout << (c < a) << std::endl;
	std::cout << (c != a) << std::endl;
	return (0);
}
