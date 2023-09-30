/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:13:09 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 16:49:38 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int execGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	std::cout << "constructed [Form: " << _name << "]" << std::endl;
}

Form::Form(const Form &src) :
	_name(src._name), _signed(src._signed),
	_signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "constructed [Form: " << _name << "]" << std::endl;
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSignStatus() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat &dude)
{
	if (dude.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}


Form	&Form::operator=(const Form &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "destructed [Form :" << _name << "]" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Form &rhs)
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
