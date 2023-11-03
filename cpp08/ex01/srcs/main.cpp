/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:05:02 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/03 14:15:11 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printNumbers();
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " <<  sp.longestSpan() << std::endl << std::endl;

	int tmp[5] = {INT_MAX, 546, 431, -0, INT_MIN};
	std::vector<int> v(tmp, tmp + 5);

	Span sp2 = Span(5);

	sp2.addNumber(v);

	sp2.printNumbers();
	std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp2.longestSpan() << std::endl << std::endl;

	int tmp2[2] = {INT_MAX, INT_MIN};
	std::vector<int> v2(tmp2, tmp2 + 2);

	Span sp3 = Span(2);

	sp3.addNumber(v2);

	sp3.printNumbers();
	std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp3.longestSpan() << std::endl << std::endl;

	return 0;
}
