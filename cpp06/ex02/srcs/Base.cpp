/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:12:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/20 14:40:08 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{}

Base	*generate(void)
{
	srand(time(NULL));

	int	num = rand() % 3 + 1;
	if (num == 1)
	{
		std::cout << "generated class A" << std::endl;
		return (new A());
	}
	else if (num == 2)
	{
		std::cout << "generated class B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "generated class C" << std::endl;
		return (new C());
	}
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "pointer identified as A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "pointer identified as B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "pointer identified as C" << std::endl;
}

void	identify(Base &ref)
{
	try
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << "reference identified as A" << std::endl;
		return ; 
	}
	catch (std::exception &e){}
	try
	{
		(void)dynamic_cast<B&>(ref);
		std::cout << "reference identified as B" << std::endl;
		return ; 
	}
	catch (std::exception &e){}
	try
	{
		(void)dynamic_cast<C&>(ref);
		std::cout << "reference identified as C" << std::endl;
		return ; 
	}
	catch (std::exception &e){}
}
