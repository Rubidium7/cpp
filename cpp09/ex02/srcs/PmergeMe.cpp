/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:38:07 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/09 12:50:22 by nlonka           ###   ########.fr       */
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
	return (*this);
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::_sortVectorPairs()
{
	for (size_t i = 0; i != _vect.size(); i++)
	{
		if (_vect.at(i).first < _vect.at(i).second)
			std::swap(_vect.at(i).first, _vect.at(i).second);
	}
}

void	PmergeMe::sortVector()
{
	_sortVectorPairs();
	_sortVectorRecursively();
	std::cout << "after:" << std::endl;
	printVector();
}

void	PmergeMe::printVector()
{
	if (_straggler != -1)
		std::cout << _straggler << std::endl;
	for (size_t i = 0; i != _vect.size(); i++)
		std::cout << _vect.at(i).first << " & " << _vect.at(i).second << std::endl;
}
