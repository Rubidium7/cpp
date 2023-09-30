/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:19:57 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 19:46:23 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	std::cout << "constructed [Form: " << _name << "]" << std::endl;
}

AForm::AForm(const AForm &src) :
	_name(src._name), _signed(src._signed),
	_signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "constructed [Form: " << _name << "]" << std::endl;
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSignStatus() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

void	AForm::beSigned(const Bureaucrat &dude)
{
	if (dude.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}


AForm	&AForm::operator=(const AForm &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw FormUnsignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	act();
}

AForm::~AForm()
{
	std::cout << "destructed [Form :" << _name << "]" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const AForm &rhs)
{
	out << "Form [" << rhs.getName() << "] is ";
	if (rhs.getSignStatus())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	out << "the grade required to sign it: " << rhs.getSignGrade() << std::endl;
	out << "the grade required to execute it: " << rhs.getExecGrade() << std::endl;
	return (out);
}
