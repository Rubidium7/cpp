

#include "Bureaucrat.hpp"

void	divorce_lawyer(Bureaucrat **mutsis, Bureaucrat **faijas)
{
	if (*mutsis)
	{
		delete *mutsis;
		*mutsis = NULL;
	}
	if (*faijas)
	{
		delete *faijas;
		*mutsis = NULL;
	}
	*faijas = NULL;
	*mutsis = NULL;
}

int main()
{
	std::cout << "hello it's 9am, welcome to your work at" << std::endl;
	std::cout << "Hallitus" << std::endl;
	Bureaucrat *mutsis = NULL;
	Bureaucrat *faijas = NULL;
	try
	{
		mutsis = new Bureaucrat("mutsis", 150);
		std::cout << *mutsis << std::endl;
		faijas = new Bureaucrat(*mutsis);
		faijas->decrementGrade();
		std::cout << *faijas << std::endl;
		divorce_lawyer(&mutsis, &faijas);
	}
	\
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
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	divorce_lawyer(&mutsis, &faijas);
	std::cout << "it's 5pm, go home" << std::endl;

	return (0);
}
