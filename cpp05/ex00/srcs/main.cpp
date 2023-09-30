

#include "Bureaucrat.hpp"

void	divorce_lawyer(Bureaucrat **mutsis, Bureaucrat **faijas)
{
	if (*mutsis)
	{
		delete *mutsis;
		*mutsis = nullptr;
	}
	if (*faijas)
	{
		delete *faijas;
		*mutsis = nullptr;
	}
	*faijas = nullptr;
	*mutsis = nullptr;
}

int main()
{
	std::cout << "hello it's 9am, welcome to your work at" << std::endl;
	std::cout << "Hallitus" << std::endl;
	Bureaucrat *mutsis = nullptr;
	Bureaucrat *faijas = nullptr;
	try
	{
		mutsis = new Bureaucrat("mutsis", 150);
		std::cout << *mutsis << std::endl;
		faijas = new Bureaucrat(*mutsis);
		faijas->decrementGrade();
		std::cout << *faijas << std::endl;
		divorce_lawyer(&mutsis, &faijas);	
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{

		std::cerr << e.what() << std::endl;
	}
	divorce_lawyer(&mutsis, &faijas);	
	try
	{
		faijas = new Bureaucrat("faijas", 2);
		std::cout << *faijas << std::endl;
		faijas->incrementGrade();
		std::cout << *faijas << std::endl;
		mutsis = new Bureaucrat("mutsis", -43);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	divorce_lawyer(&mutsis, &faijas);	
	std::cout << "it's 5pm, go home" << std::endl;

	return (0);
}
