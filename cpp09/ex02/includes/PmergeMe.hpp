/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:33:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/13 20:33:16 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <utility>
# include <sys/time.h>

# define EMPTY -1
# define ON 1
# define OFF 0
# define RED "\033[1m\033[31m"
# define RESET "\033[0m"

typedef std::pair<int, int> intpair;

typedef std::vector<intpair> pairvect;
typedef std::deque<intpair> pairdeque;
typedef std::list<intpair> pairlist;

template <typename T, typename pair>
class PmergeMe
{
	public:
		PmergeMe(int size, char **numbers);
		PmergeMe(const PmergeMe<T, pair> &src);
		~PmergeMe();

		PmergeMe<T, pair> &operator=(const PmergeMe<T, pair> &rhs);

		void	printOriginal();
		void	sort();
		void	timeDiff();
		void	printSorted();
		bool	isOk();

	private:
		PmergeMe();
		void		_pairUp(char **numbers);
		void		_sortPairs();
		void		_recursiveInsertionSort(size_t n);
		size_t		_jacobsthal(size_t n);
		size_t		_binarySearch(size_t right, int b);
		size_t		_whereInSorted(int num);
		void		_insertSmallerIntoMain();
		void		_startUpSorted();
		void		_printPair(int mode);
		char		**_og;
		T			_sorted;
		pair		_pairs;
		size_t		_amount;
		struct timeval _startTime;
		struct timeval _endTime;
};

#include "../srcs/PmergeMe.tpp"

#endif
