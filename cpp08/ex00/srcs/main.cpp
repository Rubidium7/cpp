/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:32:39 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/06 13:21:38 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	print(T container, std::string name)
{
	typename T::const_iterator it = container.begin();

	std::cout << name << " contains:" << std::endl;
	for (size_t i = 0; i != container.size(); i++)
	{
		std::cout << name << "[" << i << "] = " << *it << std::endl;
		it++;
	}
}

int main()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(-4);
	vec.push_back(5);
	vec.push_back(-433);

	print(vec, "vector");
	std::cout << "looking for -4" << std::endl;
	int found_vec = easyfind(vec, -4);
	std::cout << "found: " << found_vec << std::endl;
	
	std::list<int> list;
	
	list.push_back(-420);
	list.push_back(2);
	list.push_back(65);
	list.push_back(24);
	list.push_back(6);
	list.push_back(775);
	list.push_back(0);

	print(list, "list");
	std::cout << "looking for 0" << std::endl;
	int found_list = easyfind(list, 0);
	std::cout << "found: " << found_list << std::endl;

	std::cout << "looking for 53" << std::endl;
	try {
		found_list = easyfind(list, 53);
		std::cout << "found: " << found_list << std::endl;
	}
	catch (std::exception &e){
		std::cout << "couldn't find num" << std::endl;
	}

	return (0);
}

