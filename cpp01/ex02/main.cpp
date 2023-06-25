/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:39:53 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/25 15:47:48 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string	brain_msg = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain_msg;
	std::string	&stringREF = brain_msg;

	std::cout << "memory addresses:" << std::endl;
	std::cout << "string variable: " << &brain_msg << std::endl;
	std::cout << "string ptr: " << stringPTR << std::endl;
	std::cout << "string ref: " << &stringREF << std::endl;

	std::cout << "values:" << std::endl;
	std::cout << "string variable: " << brain_msg << std::endl;
	std::cout << "string ptr: " << *stringPTR << std::endl;
	std::cout << "string ref: " << stringREF << std::endl;
	return (0);
}
