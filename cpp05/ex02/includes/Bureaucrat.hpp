#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void	signForm(AForm &form) const;
		void	executeForm(const AForm &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The Bureaucrat grade is TOO high!!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The Bureaucrat grade is TOO low!!");
				}
		};

	private:
		Bureaucrat();
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
