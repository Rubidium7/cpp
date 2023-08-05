/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:17:53 by nlonka            #+#    #+#             */
/*   Updated: 2023/08/04 19:19:26 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "constructed [WrongCat]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "copy constructed [WrongCat]" << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "destructed [WrongCat]" << std::endl;
}

void	WrongCat::makeSound()
{
	std::cout << "[WrongCat] mouw meeiw wrongcat sounds" << std::endl;
}

