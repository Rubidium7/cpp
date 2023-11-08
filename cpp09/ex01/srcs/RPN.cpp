/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:12:50 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/08 18:56:36 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN	&RPN::operator=(const RPN &rhs)
{
	_stack = rhs._stack;
	return (*this);
}

RPN::~RPN()
{}

t_token	RPN::_identifyToken(std::string &word)
{
	t_tokens tokens[14] = {
		{"0", ZERO},
		{"1", ONE},
		{"2", TWO},
		{"3", THREE},
		{"4", FOUR},
		{"5", FIVE},
		{"6", SIX},
		{"7", SEVEN},
		{"8", EIGHT},
		{"9", NINE},
		{"+", PLUS},
		{"-", MINUS},
		{"/", DIV},
		{"*", MULTI}
	};
	for (int i = 0; i != 14; i++)
		if (tokens[i].word == word)
			return (tokens[i].token);
	return (UNKNOWN);
}

bool	RPN::_addToStack(t_token token)
{
	if (token >= PLUS && _stack.size() < 2)
		return (true);
	if (token <= 9)
		_stack.push(token);
	else
	{
		int	second = _stack.top();
		_stack.pop();
		int first = _stack.top();
		_stack.pop();
		if (token == PLUS)
			_stack.push(first + second);
		else if (token == MINUS)
			_stack.push(first - second);
		else if (token == DIV)
			_stack.push(first / second);
		else if (token == MULTI)
			_stack.push(first * second);
	}//overflow?
	return (false);
}

bool	RPN::evaluateExpression(std::string &expr)
{
	std::stringstream	ss(expr);
	std::string			tmp;
	t_token				token;

	ss >> tmp;
	while (!tmp.empty())
	{
		token = _identifyToken(tmp);
		//std::cout << "token = " << token << std::endl;
		if (token == UNKNOWN || _addToStack(token))
			return (true);
		tmp.clear();
		ss >> tmp;
	}
	if (_stack.size() != 1)
		return (true);
	std::cout << _stack.top() << std::endl;
	return (false);
}
