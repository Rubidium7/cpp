/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:33:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/08 23:01:22 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <utility>

# define VECTOR 1
# define LIST 2

typedef std::vector<std::pair<int, int> > pairvect;
typedef std::list<std::pair<int, int> > pairlist;

class PmergeMe
{
	public:
		PmergeMe(int type, int size, char **numbers);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

		void	sortVector();
		void	printVector();

	private:
		PmergeMe();
		void		_pairUpToVect(char **numbers);
		//void		_pairUpToList(char **numbers);
		void		_sortVectorPairs();
		pairvect	_vect;
		pairlist	_list;
		int			_amount;
		int			_straggler;
};

#endif
