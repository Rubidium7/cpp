/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:38:07 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/13 20:40:48 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T, typename pair>
void	PmergeMe<T, pair>::printOriginal()
{
	std::cout << "Before: ";
	for (size_t i = 0; _og[i]; i++)
	{
		std::cout << _og[i];
		if (_og[i + 1])
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

template <typename T>
typename T::iterator createIterator(size_t index, T &container)
{
	typename T::iterator it = container.begin();

	for (size_t i = 0; i != index; i++)
		it++;
	return (it);
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::_pairUp(char **numbers)
{
	size_t i = 0;

	for (; i + 1 < static_cast<size_t>(_amount - (_amount % 2)); i++)
	{
		if (i % 2)
			continue ;
		intpair tmp;
		tmp.first = atoi(numbers[i]);
		tmp.second = atoi(numbers[i + 1]);
		_pairs.push_back(tmp);
	}
	if (_amount % 2)
	{
		intpair tmp;
		if (numbers[i + 1])
			tmp.first = atoi(numbers[i + 1]);
		else
			tmp.first = atoi(numbers[i]);
		tmp.second = EMPTY;
		_pairs.push_back(tmp);
	}
}

template <typename T, typename pair>
PmergeMe<T, pair>::PmergeMe(int size, char **numbers) : _amount(size)
{
	_og = numbers;
	gettimeofday(&_startTime, NULL);
	_pairUp(numbers);
}

template <typename T, typename pair>
PmergeMe<T, pair>::PmergeMe(const PmergeMe<T, pair> &src)
{
	*this = src;
}

template <typename T, typename pair>
PmergeMe<T, pair>	&PmergeMe<T, pair>::operator=(const PmergeMe<T, pair> &rhs)
{
	_sorted = rhs._sorted;
	_pairs = rhs._pairs;
	_amount = rhs._amount;
	return *this;
}

template <typename T, typename pair>
PmergeMe<T, pair>::~PmergeMe()
{}

template <typename T, typename pair>
void	PmergeMe<T, pair>::_sortPairs()
{
	for (size_t i = 0; i != _pairs.size(); i++)
	{
		if (_pairs.at(i).first < _pairs.at(i).second)
			std::swap(_pairs.at(i).first, _pairs.at(i).second);
	}
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::_recursiveInsertionSort(size_t n)
{
	typename pair::iterator last;

	if (n <= 1)
		return ;
	_recursiveInsertionSort(n - 1);
	last = createIterator(n - 1, _pairs);
	typename pair::iterator	it = _pairs.begin();
	while (it != last)
	{
		if ((*it).first >= (*last).first)
		{
			_pairs.insert(it, *last);
			last = createIterator(n, _pairs);
			_pairs.erase(last);
			break ;
		}
		it++;
	}
}

template <typename T, typename pair>
size_t	PmergeMe<T, pair>::_jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return _jacobsthal(n - 1) + 2 * _jacobsthal(n - 2);
}

template <typename T, typename pair>
size_t	PmergeMe<T, pair>::_binarySearch(size_t right, int b)
{
	size_t left = 0;
	size_t i = 0;

	if (!right)
		return 0;
	while (left <= right && i < _sorted.size())
	{
		i = (left + right) / 2;
		if (_sorted.at(i) < b)
			left = i + 1;
		else if (_sorted.at(i) > b && !(!i || _sorted.at(i - 1) <= b))
			right = i - 1;
		else
			return i;
	}
	return _sorted.size();
}

template <typename T, typename pair>
size_t	PmergeMe<T, pair>::_whereInSorted(int num)
{
	for (size_t i = 0; i != _sorted.size(); i++)
		if (_sorted.at(i) == num)
			return (i);
	return (_sorted.size());
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::_insertSmallerIntoMain()
{
	size_t	jacob = 0;
	size_t	jacob_index = 1;
	size_t	prev_jacob = 0;
	size_t	which = 0;

	while (_sorted.size() < _amount)
	{
		prev_jacob = jacob;
		jacob = _jacobsthal(jacob_index);
		if (jacob > _pairs.size())
			jacob = _pairs.size() - 1;
		which = jacob;
		jacob_index++;
		while (which > prev_jacob)
		{
			if (which >= _pairs.size() || _pairs.at(which).second == EMPTY)
				{ which--; continue ;}
			size_t index = _binarySearch(_whereInSorted(_pairs.at(which).second), _pairs.at(which).second);
			if (index >= _sorted.size())
				return ;
			typename T::iterator where = createIterator(index, _sorted);
			_sorted.insert(where, _pairs.at(which).second);
			_pairs.at(which).second = EMPTY;
			which--;
		}
	}
}

template <typename T, typename pair>
bool	PmergeMe<T, pair>::isOk()
{
	for (size_t i = 0; i + 1 < _sorted.size(); i++)
		if (_sorted.at(i) > _sorted.at(i + 1))
			return (false);
	for (size_t i = 0; i != _pairs.size(); i++)
		if (_pairs.at(i).second != EMPTY)
			return (false);
	return (true);
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::_startUpSorted()
{
	for (size_t i = 0; i != _pairs.size(); i++)
		_sorted.push_back(_pairs.at(i).first);
	if (_pairs.at(0).second != EMPTY)
		_sorted.insert(_sorted.begin(), _pairs.at(0).second);
	_pairs.at(0).second = EMPTY;
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::timeDiff()
{
	suseconds_t milliseconds =
		(_endTime.tv_sec * 1000 + _endTime.tv_usec / 1000)
		- (_startTime.tv_sec * 1000 + _startTime.tv_usec / 1000);
	suseconds_t microseconds = _endTime.tv_usec - _startTime.tv_usec;
	if (milliseconds > 10)
		std::cout << milliseconds << " ms" << std::endl;
	else
		std::cout << microseconds << " us" << std::endl;
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::sort()
{
	_sortPairs();
	_recursiveInsertionSort(_pairs.size());
	_startUpSorted();
	_insertSmallerIntoMain();
	gettimeofday(&_endTime, NULL);

}

template <typename T, typename pair>
void	PmergeMe<T, pair>::_printPair(int mode)
{
	for (size_t i = 0; i != _pairs.size(); i++)
	{
		std::cout << "container[" << i << "] = " << _pairs.at(i).first;
		if (_pairs.at(i).second != EMPTY)
			std::cout << " & " << _pairs.at(i).second << std::endl;
		else
			std::cout << std::endl;
		if (mode && i + 1 != _pairs.size() && _pairs.at(i).first > _pairs.at(i + 1).first)
			std::cout << "not at the right place ^" << std::endl;
	}
}

template <typename T, typename pair>
void	PmergeMe<T, pair>::printSorted()
{
	std::cout << "After: ";
	for (size_t i = 0; i != _sorted.size(); i++)
	{
		std::cout << _sorted.at(i);
		if (i + 1 != _sorted.size())
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}
