/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:58:49 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/04 19:50:52 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>
# include <iostream>
# define BIGGO_TIME 37
# define BIG 10000

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack &src) : std::stack<T>(src) {};
		~MutantStack() {};

		MutantStack &operator=(const MutantStack &rhs)
		{
			if (this == &rhs)
				return (*this);
			std::stack<T>::operator=(rhs);
			return (*this);
		}
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }
};

#endif
