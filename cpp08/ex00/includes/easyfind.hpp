/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:24:02 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/02 15:21:24 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template <typename T>
int	&easyfind(T array, int num)
{
	typename T::iterator iter = find(array.begin(), array.end(), num);
	if (iter == array.end())
		throw std::exception();
	return (*iter);
}

#endif
