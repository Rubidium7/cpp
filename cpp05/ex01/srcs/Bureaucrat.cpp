/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:18:57 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 16:24:17 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "constructed [Bureaucrat: " << _name << "]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	std::cout << "copy constructed [Bureaucrat]" << std::endl;
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructed [Bureaucrat: " << _name << "]" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	if (form.getSignStatus())
	{
		std::cout << "Form '" << form.getName() << "' already signed" << std::endl;
		return ;
	}
	try 
	{
		form.beSigned(*this);
		std::cout << _name << " signed form '" << form.getName() << "'" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign form '" << form.getName();
		std::cout << "' because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}
