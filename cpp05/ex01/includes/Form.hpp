/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:13:22 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 16:50:02 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &src);
		~Form();

		Form &operator=(const Form &rhs);

		std::string	getName() const;
		bool	getSignStatus() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		void	beSigned(const Bureaucrat &dude);

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

	private:
		Form();
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &out, const Form &rhs);

#endif
