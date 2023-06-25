/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:39:03 by nlonka            #+#    #+#             */
/*   Updated: 2023/06/20 14:34:01 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	print_insult(void)
{
	std::cerr << "not a triangle you dingus" << std::endl;
	return (false);
}

int	end_message(void)
{
	std::cout << std::setw(70);
	std::cout << "Thank you for choosing our service for your triangulating needs." << std::endl;
	std::cout << std::setw(50);
	std::cout << "We hope you have a good day!" << std::endl;
	return (0);
}

void	print_ans(const Point a, const Point b, const Point c, const Point point, bool ans)
{
	std::cout << "Point: ";
	point.printPoint();
	if (ans)
		std::cout << "is within triangle:" << std::endl;
	else
		std::cout << "is not within triangle:" << std::endl;
	a.printPoint();
	b.printPoint();
	c.printPoint();
}

int	get_point(std::string id, float *xy)
{
	std::string	buf;

	while (1)
	{
		std::cout << "give [x] for point " << id << ":" << std::endl;
		if (!std::getline(std::cin, buf))
			break ;
		xy[0] = atof(buf.c_str());
		if (!xy[0] && strcmp(buf.c_str(), "0"))
			continue ;
		std::cout << "give [y] for point " << id << ":" << std::endl;
		if (!std::getline(std::cin, buf))
			break ;
		xy[1] = atof(buf.c_str());
		if (!xy[1] && strcmp(buf.c_str(), "0"))
			continue ;
		return (0);
	}
	return (1);
}

bool	is_triangle(const Point a, const Point b, const Point c)
{
	if (a.getX() == b.getX() && (b.getX() == c.getX() || a.getY() == b.getY()))
		return (print_insult());
	if ((a.getY() == b.getY() || b.getX() == c.getX()) && b.getY() == c.getY())
		return (print_insult());
	if (a.getY() == c.getY() && a.getX() == c.getX())
		return (print_insult());
	if (on_line(a, b, c) || on_line(b, c, a) || on_line(c, a, b))
		return (print_insult());
	return (true);
}

int	test_mode(void)
{
	float	xy[2];

	if (get_point("a", xy))
		return (1);
	Point	a(xy[0], xy[1]);

	if (get_point("b", xy))
		return (1);
	Point	b(xy[0], xy[1]);
	
	if (get_point("c", xy))
		return (1);
	Point	c(xy[0], xy[1]);
	
	if (get_point("to look for", xy))
		return (1);
	Point	test(xy[0], xy[1]);

	if (is_triangle(a, b, c))
		print_ans(a, b, c, test, bsp(a, b, c, test));
	return (0);
}

int main(void)
{
	std::string	buf;

	while (1)
	{
		if (test_mode())
			return (1);		
		std::cout << "want to continue?" << std::endl << "[y/n]" << std::endl;
		while (1)
		{
			if (!std::getline(std::cin, buf) || !strcmp("n", buf.c_str()))
				return (end_message());
			if (!strcmp("y", buf.c_str()))
				break ;
			std::cout << "y or n, please" << std::endl;
		}
	}
	return (end_message());
}
