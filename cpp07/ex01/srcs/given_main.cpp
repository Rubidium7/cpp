/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   given_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:01:47 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/31 14:38:12 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Awesome
{
	public:
		Awesome (void) : _n(42) {return;}
		int get(void) const {return this->_n;}
	private:
		int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get(); return o;}

template <typename T>
void print(T const &x) {std::cout << x << std::endl; return;}
int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);

	return (0);
}
