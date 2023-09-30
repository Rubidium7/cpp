/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:53:26 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 20:30:48 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form	form1("mutsis_is_faijas", 1, 10);
	Form	tmp("execute_all_the_french", 49, 150);
	Form	form2(tmp);
	Form	form3("free_harkis_rouheseos_for_all", 130, 2);
	Bureaucrat	anti_mutsis("anti_mutsis", 49);

	std::cout << std::endl << form1;
	std::cout << std::endl << form2;
	std::cout << std::endl << form3;
	std::cout << std::endl << anti_mutsis << std::endl << std::endl;
	anti_mutsis.signForm(form1);
	anti_mutsis.signForm(form2);
	anti_mutsis.signForm(form3);

	std::cout << std::endl << form2;

	try
	{
		std::cout << std::endl << "trying to sign form 'why_u_do_this':" << std::endl;
		Form	fail("why_u_do_this", 0, 4);
	}
	catch (std::exception &e)
	{
		std::cout <<  e.what() << std::endl << std::endl;
	}
	return (0);
}
