/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:57:31 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 18:33:23 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("presidential_pardon_form", 25, 5), _target(target)
{
	std::cout << "constructed [PresidentialPardonForm]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target)
{
	std::cout << "copy constructed [PresidentialPardonForm]" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

void	PresidentialPardonForm::act() const
{
	std::cout << _target << " has been pardoned by President Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destructed [PresidentialPardonForm]" << std::endl;
}
