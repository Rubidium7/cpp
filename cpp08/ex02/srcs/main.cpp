/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:28:26 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/04 19:43:27 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>
#include <ctime>

void	biggo_test()
{
	std::srand(std::time(NULL));
	int					num;
	std::list<int>		ls;
	MutantStack<int>	ms;

	for (size_t i = 0; i != BIG; i++)
	{
		num = rand();
		std::cout << "inserted [" << num << "]" << std::endl;
		ls.push_back(num);
		ms.push(num);
	}
	std::list<int>::iterator lit = ls.begin();
	MutantStack<int>::iterator it = ms.begin();
	bool diff = false;

	std::cout << "comparing stacks..." << std::endl;
	while (it != ms.end() && lit != ls.end())
	{
		if (*it != *lit)
			diff = true;
		it++;
		lit++;
	}
	if (diff)
		std::cout << "difference found :(" << std::endl;
	else
		std::cout << "no difference :)" << std::endl;
}

int main()
{
	size_t i = 0;

	std::cout << "test with list:" << std::endl;

	std::list<int>	ls;

	if (ls.empty())
		std::cout << "list is empty" << std::endl;
	ls.push_back(5);
	ls.push_back(17);

	std::cout << "back of list: " << ls.back() << std::endl;

	ls.pop_back();

	std::cout << "list size: " <<  ls.size() << std::endl;

	ls.push_back(3);
	ls.push_back(5);
	ls.push_back(45);
	ls.push_back(75);
	ls.push_back(99);
	ls.push_back(-432);
	ls.push_back(-421);
	ls.push_back(-5);
	ls.push_back(542);
	ls.push_back(120);
	ls.push_back(-43243223);
	ls.push_back(79384);
	ls.push_back(23);
	ls.push_back(532);
	ls.push_back(943);
	ls.push_back(737);
	ls.push_back(0);

	std::list<int>::iterator lit = ls.begin();
	std::list<int>::iterator lite = ls.end();

	++lit;
	--lit;
	std::cout << "list contents:" << std::endl;
	while (lit != lite)
	{
		std::cout << i << "[" << *lit << "]" << std::endl;
		++lit;
		i++;
	}
	i--;
	std::list<int>::reverse_iterator rlit = ls.rbegin();
	std::list<int>::reverse_iterator rlite = ls.rend();

	std::cout << "list contents in reverse:" << std::endl;
	while (rlit != rlite)
	{
		std::cout << i << "[" << *rlit << "]" << std::endl;
		rlit++;
		i--;
	}
	i = 0;
	std::list<int> swap;

	std::cout << "swapping lists.." << std::endl;
	swap.swap(ls);
	
	std::cout << "old stacks size now: " << ls.size() << std::endl;
	std::cout << "new stacks size now: " << swap.size() << std::endl;
	swap.swap(ls);
	std::cout << std::endl << "now with mutantstack:" << std::endl;
	MutantStack<int>	mstack;

	if (mstack.empty())
		std::cout << "mutantstack is empty" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "on top of mutantstack: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mutantstack size: " <<  mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(45);
	mstack.push(75);
	mstack.push(99);
	mstack.push(-432);
	mstack.push(-421);
	mstack.push(-5);
	mstack.push(542);
	mstack.push(120);
	mstack.push(-43243223);
	mstack.push(79384);
	mstack.push(23);
	mstack.push(532);
	mstack.push(943);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "mutantstack contents:" << std::endl;
	while (it != ite)
	{
		std::cout << i << "[" << *it << "]" << std::endl;
		++it;
		i++;
	}
	i--;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "mutantstack contents in reverse:" << std::endl;
	while (rit != rite)
	{
		std::cout << i << "[" << *rit << "]" << std::endl;
		rit++;
		i--;
	}

	MutantStack<int> swappie;

	std::cout << "swapping stacks.." << std::endl;
	swappie.swap(mstack);
	
	std::cout << "old stacks size now: " << mstack.size() << std::endl;
	std::cout << "new stacks size now: " << swappie.size() << std::endl;

	swappie.swap(mstack);
	std::cout << std::endl << "comparing list and stack contents.." << std::endl;
	bool diff = false;

	lit = ls.begin();
	it = mstack.begin();

	while (lit != ls.end() && it != mstack.end())
	{
		if (*lit != *it)
			diff = true;
		lit++;
		it++;
	}
	if (diff)
		std::cout << " > the contents differ :d" << std::endl;
	else
		std::cout << " > the contents are the same :)" << std::endl;

	std::stack<int> s(mstack);

	std::string buf;

	std::cout << "ready for the biggo test???" << std::endl;
	std::cout << "(y/n)" << std::endl;
	while (BIGGO_TIME)
	{
		if (!std::getline(std::cin, buf) || buf == "n" || buf == "N")
		{
			std::cout << "ok bye loser" << std::endl;
			return 1;
		}
		if (buf == "y" || buf == "Y")
			break ;
	}
	biggo_test();
	return 0;
}
