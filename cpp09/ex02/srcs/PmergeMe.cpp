/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:38:07 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/10 18:55:18 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::_pairUpToVect(char **numbers)
{
	for (size_t i = 0; i + 1 != static_cast<size_t>(_amount - (_amount % 2)); i++)
	{
		if (i % 2)
			continue ;
		std::pair<int, int> tmp;
		tmp.first = atoi(numbers[i]);
		tmp.second = atoi(numbers[i + 1]);
		_vect.push_back(tmp);
	}
	std::cout << "before:" << std::endl;
	printVector();
}

PmergeMe::PmergeMe(int type, int size, char **numbers) : _amount(size), _straggler(-1)
{
	if (type != LIST && type != VECTOR)
		throw std::exception();
	if (size % 2)
	{
		_straggler = atoi(numbers[0]);
		numbers += 1;
	}
	if (type == VECTOR)
		_pairUpToVect(numbers);
	//else
		//_pairUpToList(numbers);
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs)
{
	_vect = rhs._vect;
	_list = rhs._list;
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::_sortPairs(pairvect &vect)
{
	for (size_t i = 0; i != vect.size(); i++)
	{
		if (vect.at(i).first < vect.at(i).second)
			std::swap(vect.at(i).first, vect.at(i).second);
	}
}

void	PmergeMe::_recursiveInsertionSort(pairvect &vect, size_t n)
{
	int last;

	if (n <= 1)
		return ;
	last = vect.at(n - 1).first;
	_recursiveInsertionSort(vect, n - 1);
	pairvect::iterator	it = vect.begin();
	while ((*it).first != last)
	{
		if ((*it).first >= last)
		{
			pairvect::iterator where = it;
			std::pair<int, int> tmp = vect.at(n - 1);
			while ((*it).first != last)
				it++;
			vect.erase(it);
			vect.insert(where, tmp);
			break ;
		}
		it++;
	}
}

size_t	PmergeMe::_jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return _jacobsthal(n - 1) + 2 * _jacobsthal(n - 2);
}

void	PmergeMe::_jacobsthalArray(size_t size)
{
	size_t	jacob_index = 3;
	size_t	begin;
	size_t	end = 1;

	_jarray.push_back(0);
	_jarray.push_back(1);
	while (_jacobsthal(jacob_index) < size - 1)
	{
		begin = _jacobsthal(jacob_index);
		_jarray.push_back(begin);
		for (size_t n = begin - 1; n != end; n--)
			_jarray.push_back(n);
		end = begin;
		jacob_index++;
	}
	while (begin++ != size)
		_jarray.push_back(begin);
	for (size_t i = 0; i != _jarray.size(); i++)
	   std::cout << _jarray.at(i) << std::endl;	
}

void	PmergeMe::_insertSmallerIntoMain(pairvect &vect)
{
	for (size_t i = 0; i != vect.size(); i++)
		_sortedVect.at(i) = vect.at(i).first;
	for (size_t i = 0; i != vect.size(); i++)
	{
		//size_t which = _jarray.at(i);
	}
	(void)vect;
}

void	PmergeMe::sortVector()
{
	_sortPairs(_vect);
	_recursiveInsertionSort(_vect, _vect.size());
	std::cout << "after:" << std::endl;
	printVector();
	std::cout << "jacobsthal:" << std::endl;
	_jacobsthalArray(_vect.size() + 3);
	//_insertSmallerIntoMain(_vect);
}

void	PmergeMe::printVector()
{
	if (_straggler != -1)
		std::cout << _straggler << std::endl;
	for (size_t i = 0; i != _vect.size(); i++)
	{
		std::cout << _vect.at(i).first;
		if (_vect.at(i).second != EMPTY)
			std::cout << " & " << _vect.at(i).second << std::endl;
	}
}
