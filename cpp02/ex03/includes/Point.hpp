/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:26:56 by nlonka            #+#    #+#             */
/*   Updated: 2023/06/19 15:22:26 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		~Point();

		Point	&operator=(const Point &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
		void	printPoint(void) const;

	private:
		const Fixed _x;
		const Fixed _y;
};

bool	on_line(const Point a, const Point b, const Point point);
bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
