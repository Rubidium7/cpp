/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:06:16 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/11 19:01:45 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
	
	private:
		Contact contact[8];
		int		index;
		int		biggest;
		int		exist;
		int		check_val(std::string &first_name, std::string &last_name, std::string &nickname,
			   	std::string &phone_number, std::string &secret);

};

#endif
