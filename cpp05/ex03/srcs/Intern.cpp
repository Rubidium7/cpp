/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:46:32 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 20:30:05 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "constructed [Intern]" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "copy constructed [Intern]" << std::endl;
	*this = src;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string	forms[3] = {"shrubbery creation",
		"robotomy request", "presidential pardon"};
	AForm *(Intern::*makers[])(std::string &target) = {&Intern::_shrubMaker,
		&Intern::_roboMaker, &Intern::_prezMaker};

	for (int i = 0; i != 3; i++)
	{
		if (forms[i] == form_name)
			return ((this->*makers[i])(target));
	}
	std::cout << "our intern is not familier with this '" << form_name << "' form" << std::endl;
	return (NULL);
}

AForm	*Intern::_shrubMaker(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::_roboMaker(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::_prezMaker(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Intern::~Intern()
{
	std::cout << "destructed [Intern]" << std::endl;
}
