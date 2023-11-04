/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:29:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/04 20:25:53 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{}

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span &src)
{
	*this = src;
}

Span	&Span::operator=(const Span &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_maxSize = rhs._maxSize;
	this->_store.clear();
	for (size_t i = 0; i != rhs._store.size(); i++)
		this->_store.push_back(rhs._store.at(i));
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_store.size() == _maxSize)
		throw std::exception();
	_store.push_back(num);
}

void	Span::addNumber(int num, size_t amount)
{
	if (amount <= 0)
		return ;
	if (_store.size() + amount >= _maxSize)
		throw std::exception();
	_store.insert(_store.end(), amount, num);
}

void	Span::addNumber(std::vector<int> numbers)
{
	if (_store.size() + numbers.size() > _maxSize)
		throw std::exception();
	_store.insert(_store.end(), numbers.begin(), numbers.end());
}

unsigned int Span::shortestSpan() const
{
	unsigned int diff = UINT_MAX;

	if (_store.size() < 2)
		throw std::exception();
	std::vector<int> sorted = this->_store;
	std::sort(sorted.begin(), sorted.end());
	for (size_t i = 0; i + 1 < sorted.size(); i++)
	{
		if (static_cast<unsigned int>(sorted.at(i + 1) - sorted.at(i)) < diff)
			diff = static_cast<unsigned int>(sorted.at(i + 1) - sorted.at(i));
	}
	return (diff);
}

unsigned int Span::longestSpan() const
{
	if (_store.size() < 2)
		throw std::exception();
	int max = *max_element(_store.begin(), _store.end());
	int min = *min_element(_store.begin(), _store.end());
	return max - min;
}

void	Span::printNumbers() const
{
	for (size_t i = 0; i != _store.size(); i++)
		std::cout << "vector[" << i << "] = " << _store.at(i) << std::endl;
}

size_t	Span::size() const { return (_store.size()); }

Span::~Span()
{}
