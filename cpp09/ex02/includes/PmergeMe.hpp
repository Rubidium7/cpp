/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:33:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/10 17:50:00 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <utility>

# define EMPTY -1
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
		void		_sortPairs(pairvect &vect);
		void		_recursiveInsertionSort(pairvect &vect, size_t n);
		size_t		_jacobsthal(size_t n);
		void		_jacobsthalArray(size_t size);
		void		_insertSmallerIntoMain(pairvect &vect);
		std::vector<int> _sortedVect;
		pairvect	_vect;
		pairlist	_list;
		std::vector<size_t>	_jarray;
		int			_amount;
		int			_straggler;
};

#endif
