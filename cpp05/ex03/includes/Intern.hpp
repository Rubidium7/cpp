/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:44:35 by nlonka            #+#    #+#             */
/*   Updated: 2023/09/30 20:27:29 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &rhs);
		
		AForm	*makeForm(std::string form_name, std::string target);

	private:
		AForm	*_shrubMaker(std::string &target);
		AForm	*_roboMaker(std::string &target);
		AForm	*_prezMaker(std::string &target);
};

#endif
