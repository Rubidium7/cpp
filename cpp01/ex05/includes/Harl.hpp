/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:49:00 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/26 21:20:16 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cctype>
# include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);

	private:
		std::string	levels[4];
		void	(Harl::*modes[4])(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

void	print_levels(void);

#endif
