/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:11:04 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/16 17:40:27 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <limits>
# include <exception>

typedef enum e_token
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	PLUS,
	MINUS,
	DIV,
	MULTI,
	UNKNOWN
} t_token;

typedef struct s_tokens
{
	std::string word;
	t_token		token;
} t_tokens;

class RPN
{
	public:
		RPN();
		RPN(const RPN &src);
		~RPN();

		RPN &operator=(const RPN &rhs);

		bool	evaluateExpression(std::string &expr);
	
	private:
		t_token			_identifyToken(std::string &token);
		bool			_checkOverflow(t_token token, long first, long second);
		bool			_addToStack(t_token token);
		std::stack<int> _stack;
};

#endif
