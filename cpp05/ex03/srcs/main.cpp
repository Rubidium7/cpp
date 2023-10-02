/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:53:26 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 20:44:45 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern linkedin_haver;
	Bureaucrat marvin("marvin", 42);
	Bureaucrat meta("you", 150);
	Bureaucrat dolphin("dolphin", 1);
	Bureaucrat papyrus("cool dude", 137);

	std::cout << std::endl;

	AForm *not_form = linkedin_haver.makeForm("getting paid what they're worth", "mutsis");
	(void)not_form;
	AForm *rform = linkedin_haver.makeForm("robotomy request", "marvin");
	AForm *pform = linkedin_haver.makeForm("presidential pardon", "lionel");
	AForm *sform = linkedin_haver.makeForm("shrubbery creation", "cool");

	std::cout << std::endl;
	std::cout << *rform << std::endl;
	std::cout << *pform << std::endl;
	std::cout << *sform << std::endl;
	meta.signForm(*rform);
	marvin.signForm(*rform);
	std::cout << std::endl;
	marvin.executeForm(*rform);
	std::cout << std::endl;
	dolphin.executeForm(*sform);
	papyrus.signForm(*sform);
	papyrus.executeForm(*sform);
	std::cout << std::endl;
	meta.signForm(*pform);
	dolphin.signForm(*pform);
	std::cout << std::endl;
	dolphin.executeForm(*pform);
	std::cout << std::endl;

	delete rform;
	delete pform;
	delete sform;
	return (0);
}
