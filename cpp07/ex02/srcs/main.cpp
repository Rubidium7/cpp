/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:37:02 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/01 14:12:03 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Fixed.hpp"

#define SIZE 6
#define BIZE 10
#define DIZE 3

int main()
{
	Array<int> a(SIZE);

	std::cout << "size of array a = " << a.size() << std::endl;

	for (size_t i = 0; i != SIZE; i++)
		a[i] = i + 37;

	for (size_t i = 0; i != SIZE; i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	try {
		a[-1] = 69;
	}
	catch (std::exception &e) {
		std::cout << "couldn't access index -1" << std::endl;
	}
	try {
		a[SIZE] = 420;
	}
	catch (std::exception &e) {
		std::cout << "couldn't access index " << SIZE << std::endl;
	}
	Array<std::string> b(BIZE);
	Array<size_t>		key(BIZE);

	for (size_t i = 0; i != BIZE; i++)
	{
		if (i < 2)
			key[i] = (i * 2) + 4;
		else if (i < 4 || i > 6)
			key[i] = i;
		else if (i < 5)
			key[i] = 75 / 15;
		else
			key[i] = i - 5;
	}

	b[0] = "the";
	b[1] = "french";
	b[2] = "always";
	b[3] = "said";
	b[5] = "that";
	b[4] = "lol";
	b[7] = "should";
	b[6] = "I";
	b[8] = "be";
	b[9] = "banned";

	for (size_t i = 0; i != BIZE; i++)
	{
		std::cout << b[key[i]];
		if (i + 1 != BIZE)
			std::cout << " ";
		else
			std::cout << std::endl;
	}

	Array<int> c;

	std::cout << "size of array c before = " << c.size() << std::endl;

	c = a;

	std::cout << "size of array c after = " << c.size() << std::endl;

	for (size_t i = 0; i != SIZE; i++)
	   std::cout << "c[" << i << "] = " << c[i] << std::endl;	

	Array<Fixed> d(DIZE);

	d[0] = 42.2f; 
	d[1] = -0.01f;
	d[2] = 420;

	for (size_t i = 0; i != DIZE; i++)
		std::cout << "d[" << i << "] = " << d[i] << std::endl;

	//const test (shouldn't compile)
	//const Array<int> const_tab(DIZE);
	//const_tab[0] = 420;

	return (0);
}
