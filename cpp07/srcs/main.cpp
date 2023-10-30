/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:12:31 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/30 19:44:57 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Fixed.hpp"

int main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Fixed af(6.09f);
	Fixed bf(42);
	Fixed cf(0);

	std::cout << "fixed a: " << af << std::endl;
	std::cout << "fixed b: " << bf << std::endl;
	std::cout << "fixed c: " << cf << std::endl;

	::swap(af, bf);
	std::cout << "after swap:" << std::endl;
	std::cout << "fixed a: " << af << std::endl;
	std::cout << "fixed b: " << bf << std::endl;

	if (::min(af, bf) == af)
		std::cout << "smaller is a" << std::endl;
	else
		std::cout << "smaller is b" << std::endl;

	if (::max(cf, bf) == cf)
		std::cout << "c is bigger than b" << std::endl;
	else
		std::cout << "b is bigger than c" << std::endl;


	return 0;
}
