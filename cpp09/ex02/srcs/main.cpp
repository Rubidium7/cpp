/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:34:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/10 18:01:21 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	karen(std::string complaint)
{
	std::cout << "Error: " << complaint << std::endl;
	return (true);
}

bool	has_duplicate(char **av)
{
	if (!av[0] || !av[1])
		return (false);
	for (size_t i = 1; av[i]; i++)
	{
		if (!strcmp(av[0], av[i]))
			return (true);
	}
	return (has_duplicate(av + 1));
}

bool	not_valid_num(std::string str)
{
	if (str.empty())
		return karen("non-numeric character.");
	if (str.at(0) == '-')
		return karen("only positive numbers.");
	if (str.at(0) == '+')
		return karen("plus signs scare me..");
	for (size_t i = 0; i != str.size(); i++)
		if (!isdigit(str.at(i)))
			return karen("non-numeric character.");
	if (str.size() > 10)
		return karen("number bigger than an int.");
	int num = atoi(str.c_str());
	if (num < 0)
		return karen("number bigger than an int.");
	return (false);
}

bool	validate_input(char **av)
{
	for (size_t i = 0; av[i]; i++)
	{
		if (not_valid_num(av[i]))
			return (true);
	}
	//if (has_duplicate(av))
	//	return karen("duplicates found.");
	return (false);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	if (validate_input(av + 1))
		return 1;
	//time
	PmergeMe	vectorMerge(VECTOR, ac - 1, av + 1);

	vectorMerge.sortVector();
	//time
	//PmergeMe	listMerge(LIST, ac - 1, av + 1);
	//std::cout << "yo" << std::endl;
	return 0;
}
