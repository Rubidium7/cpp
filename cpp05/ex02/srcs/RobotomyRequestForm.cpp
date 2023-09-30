/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:08:27 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 19:41:01 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("robotomy_request_form", 72, 45), _target(target)
{
	std::cout << "constructed [RobotomyRequestForm]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target)
{
	std::cout << "copy constructed [RobotomyRequestForm]" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

void	RobotomyRequestForm::act() const
{
	srand(time(NULL));

	std::cout << "* BBZZTTT RRRHH BRRRRMRRRRRRR *" << std::endl;
	std::cout << "* BRRRRRRRRIIIIIIIIIIIIIIIIIIWWWRMMMMMMRM *" << std::endl;
	std::cout << "* BRRIIFFFffffFfHhHhhhhhhhhhhhhhh.. *" << std::endl;
	if (rand() % 2)
	{
		std::cout << _target << " has been Robotomized successfully" << std::endl;
		std::cout << _target << ": yaay" << std::endl;
	}
	else
	{
		std::cout << _target << "'s Robotomy failed... o.o" << std::endl;
		std::cout << _target << ": bzzzt.." << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destructed [RobotomyRequestForm]" << std::endl;
}
