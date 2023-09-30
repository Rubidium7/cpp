/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:48:06 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 18:51:43 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery_creation_form", 145, 137), _target(target)
{
	std::cout << "constructed [ShrubberyCreationForm]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : 
	AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target)
{
	std::cout << "copy constructed [ShrubberyCreationForm]" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::act() const
{
	std::ofstream out(_target + "_shrubbery");

	if (!out.is_open())
	{
		std::cout << "Shrubberization process failed.." << std::endl;
		return ;
	}
	out << "    _| |_    _| |_   _| |_    " << std::endl;
	out << "   |     |  |     | |     |   " << std::endl;
	out << ".....|_|......|_|.....|_|....." << std::endl;
	out.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destructed [ShrubberyCreationForm]" << std::endl;
}
