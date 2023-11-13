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

void	printer(std::vector<int> vect);

void	PmergeMe::_pairUpToVect(char **numbers)
{
	size_t i = 0;

	for (; i + 1 < static_cast<size_t>(_amount - (_amount % 2)); i++)
	{
		if (i % 2)
			continue ;
		std::pair<int, int> tmp;
		tmp.first = atoi(numbers[i]);
		tmp.second = atoi(numbers[i + 1]);
		_vect.push_back(tmp);
	}
	if (_amount % 2)
	{
		std::pair<int, int> tmp;
		tmp.first = atoi(numbers[i + 1]);
		tmp.second = EMPTY;
		_vect.push_back(tmp);
	}
}

PmergeMe::PmergeMe(int type, int size, char **numbers) : _amount(size)
{
	if (type != LIST && type != VECTOR)
		throw std::exception();
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
		return 1;
	if (n == 1)
		return 3;
	return n + 2 * _jacobsthal(n - 1);
}



size_t	PmergeMe::_binarySearch(std::vector<int> &vect, size_t right, int b)
{
	size_t left = 0;
	size_t i = 0;

	if (!right)
		return 0;
	while (left <= right && i <= vect.size())
	{
		i = (left + right) / 2;
		if (vect.at(i) < b)
			left = i + 1;
		else if (vect.at(i) > b && !(!i || vect.at(i - 1) <= b))
			right = i - 1;
		else
			return i;
	}
	return vect.size();
}

size_t	PmergeMe::_indexOf(std::vector<int> &vect, int num)
{
	for (size_t i = 0; i != vect.size(); i++)
		if (vect.at(i) == num)
			return (i);
	return (vect.size());
}

std::vector<int>::iterator	PmergeMe::_createIterator(size_t index, std::vector<int> &vect)
{
	std::vector<int>::iterator it = vect.begin();

	for (size_t i = 0; i != index; i++)
		it++;
	return (it);
}

void	PmergeMe::_insertSmallerIntoMain(pairvect &vect)
{
	size_t	jacob = 0;
	size_t	prev_jacob = 0;
	size_t	which = 0;

	for (size_t i = 0; i != vect.size(); i++)
		_sortedVect.push_back(vect.at(i).first);
	if (vect.at(0).second != EMPTY)
		_sortedVect.insert(_sortedVect.begin(), vect.at(0).second);
	vect.at(0).second = EMPTY;
	while (_sortedVect.size() < _amount)
	{
		prev_jacob = jacob;
		jacob = _jacobsthal(prev_jacob);
		if (jacob > vect.size())
			jacob = vect.size() - 1;
		which = jacob;
		while (which > prev_jacob)
		{
			if (which >= vect.size() || vect.at(which).second == EMPTY)
				{ which--; continue ;}
			size_t index = _binarySearch(_sortedVect, _indexOf(_sortedVect, vect.at(which).first), vect.at(which).second);
			if (index >= _sortedVect.size())
				{std::cout << "ERROR" << std::endl; return ;}
			std::vector<int>::iterator where = _createIterator(index, _sortedVect);
			_sortedVect.insert(where, vect.at(which).second);
			vect.at(which).second = EMPTY;
			which--;
		}
	}
}

bool	PmergeMe::_isOk(std::vector<int> &sorted, pairvect &sec)
{
	for (size_t i = 0; i + 1 < sorted.size(); i++)
		if (sorted.at(i) > sorted.at(i + 1))
			{ std::cout << "at " << i << std::endl; return (false);}
	for (size_t i = 0; i != sec.size(); i++)
		if (sec.at(i).second != EMPTY)
			return (false);
	return (true);
}

void	PmergeMe::sortVector()
{
	_sortPairs(_vect);
	_recursiveInsertionSort(_vect, _vect.size());
	std::cout << "sorted pairs:" << std::endl;
	printVector();
	_insertSmallerIntoMain(_vect);
	std::cout << "after:" << std::endl;
	printer(_sortedVect);
	//std::cout << std::endl << "sec vect after:" << std::endl;
	//printVector();	
	std::cout << std::endl;
	if (_isOk(_sortedVect, _vect))
		std::cout << "sort successful" << std::endl;
	else
		std::cout << "sort fucked up.." << std::endl;
}

void	PmergeMe::printVector()
{
	for (size_t i = 0; i != _vect.size(); i++)
	{
		std::cout << "vect[" << i << "] = " << _vect.at(i).first;
		if (_vect.at(i).second != EMPTY)
			std::cout << " & " << _vect.at(i).second << std::endl;
		else
			std::cout << std::endl;
	}
}

void	printer(std::vector<int> vect)
{
	for (size_t i = 0; i != vect.size(); i++)
		std::cout << "vect[" << i << "] = " << vect.at(i) << std::endl;
}

