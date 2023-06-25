/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:31:27 by nlonka            #+#    #+#             */
/*   Updated: 2023/06/19 15:27:05 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::~Point(void)
{}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}

void	Point::printPoint(void) const
{
	std::cout << "[" << (getX()) << "]";
	std::cout << "[" << (getY()) << "]" << std::endl;
}

Point	&Point::operator=(const Point &rhs)
{
	const_cast<Fixed&>(_x) = rhs._x;
	const_cast<Fixed&>(_y) = rhs._y;
	return (*this);
}
