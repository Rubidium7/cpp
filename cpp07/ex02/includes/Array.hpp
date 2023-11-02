/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:03:37 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/01 14:08:48 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);

		Array<T>	&operator=(const Array<T> &other);
		T			&operator[](const unsigned int index);
		const T		&operator[](const unsigned int index) const;

		unsigned int size() const;

		~Array();
	
	private:
		T				*_array;
		unsigned int	_size;
};

#include "../srcs/Array.tpp"

#endif
