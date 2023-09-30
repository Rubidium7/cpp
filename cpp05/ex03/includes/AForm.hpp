/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:21:35 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 19:32:43 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <stdexcept>
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm &operator=(const AForm &rhs);

		std::string	getName() const;
		bool	getSignStatus() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		void	beSigned(const Bureaucrat &dude);
		void	execute(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("grade is too high :) to do this!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("grade is too low :( to do this!");
				}
		};

		class FormUnsignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("the form is not signed, the little scoundrel");
				}
		};

	protected:
		virtual void	act() const = 0;

	private:
		AForm();
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &out, const AForm &rhs);

#endif
