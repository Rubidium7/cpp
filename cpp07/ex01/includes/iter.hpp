/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:23:29 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/31 14:39:03 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void iter(T *ptr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i != len; i++)
		f(ptr[i]);
}

template <typename T>
void iter(T *ptr, size_t len, void (*f)(T &))
{
    for (size_t i = 0; i != len; i++)
        f(ptr[i]);
}

#endif
