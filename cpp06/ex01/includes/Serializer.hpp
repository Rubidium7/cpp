/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:54:43 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/19 15:13:12 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
	int num;
};

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();

		Serializer &operator=(const Serializer &rhs);

};

#endif
