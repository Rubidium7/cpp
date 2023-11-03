/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:30 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/03 14:00:34 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &rhs);

		void	addNumber(int num);
		void	addNumber(int num, size_t amount);
		void	addNumber(std::vector<int> numbers);

		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;

		void	printNumbers() const;
		
	private:
		Span();
		std::vector<int>	_store;
		unsigned int		_maxSize;
};

#endif
