/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:05:02 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/04 20:24:11 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

void	big()
{
	std::srand(std::time(NULL));
	Span sp = Span(WAY_MORE);
	int num;
	for (size_t i = 0; i != WAY_MORE; i++)
	{
		num = rand();
		if (rand() % 3)
			num -= rand();
		sp.addNumber(num);
	}
	std::cout << "added " << sp.size() << " numbers to span" << std::endl;
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " <<  sp.longestSpan() << std::endl << std::endl;
}

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


	Span sp3 = Span(2);

	std::cout << "trying to find span in empty uh span:" << std::endl;
	try {
		sp3.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << "didn't work :)" << std::endl << std::endl;
	}
	sp3.addNumber(INT_MIN);
	sp3.addNumber(INT_MAX);

	sp3.printNumbers();
	std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp3.longestSpan() << std::endl << std::endl;

	std::cout << "trying to add a number to a full span:" << std::endl;
	try {
		sp3.addNumber(69);
	}
	catch (std::exception &e) {
		std::cout << "didn't work :^)" << std::endl << std::endl;
	}

	std::cout << "testing " << WAY_MORE << " numbers:" << std::endl;
	big();

	return 0;
}
