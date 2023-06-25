/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:48:44 by nlonka            #+#    #+#             */
/*   Updated: 2023/06/20 14:33:59 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	fab(const Fixed &val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

bool	on_line(const Point a, const Point b, const Point point)
{
	Fixed slope1 = (b.getY() - a.getY()) / (b.getX() - a.getX());
	Fixed slope2 = (b.getY() - point.getY()) / (b.getX() - point.getX());
	return (slope1 == slope2);
}

Fixed	calc_triangle_area(const Point a, const Point b, const Point c)
{
	Fixed	part1 = (a.getX() * (b.getY() - c.getY()));
	Fixed	part2 = (b.getX() * (c.getY() - a.getY()));
	Fixed	part3 = (c.getX() * (a.getY() - b.getY()));

	return (fab((part1 + part2 + part3)) / 2);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	if (on_line(a, b, point) || on_line(b, c, point) || on_line(c, a, point))
		return (false);
	Fixed	triangle_area = calc_triangle_area(a, b, c);
	Fixed	comp_area1 = calc_triangle_area(a, b, point);
	Fixed	comp_area2 = calc_triangle_area(a, point, c);
	Fixed	comp_area3 = calc_triangle_area(point, b, c);
	return (triangle_area + 0.01f > comp_area1 + comp_area2 + comp_area3);
}
