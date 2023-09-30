/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:53:26 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 20:31:00 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat marvin("marvin", 42);
	Bureaucrat meta("you", 150);
	Bureaucrat dolphin("dolphin", 1);
	Bureaucrat papyrus("cool dude", 137);
	RobotomyRequestForm rform("marvin");
	PresidentialPardonForm pform("lionel");
	ShrubberyCreationForm sform("cool");

	std::cout << std::endl;
	std::cout << rform << std::endl;
	std::cout << pform << std::endl;
	std::cout << sform << std::endl;
	std::cout << std::endl;
	meta.signForm(rform);
	marvin.signForm(rform);
	std::cout << std::endl;
	marvin.executeForm(rform);
	std::cout << std::endl;
	dolphin.executeForm(sform);
	papyrus.signForm(sform);
	papyrus.executeForm(sform);
	std::cout << std::endl;
	meta.signForm(pform);
	dolphin.signForm(pform);
	std::cout << std::endl;
	dolphin.executeForm(pform);
	std::cout << std::endl;

	return (0);
}
