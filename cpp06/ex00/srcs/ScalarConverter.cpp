/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:50:56 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/19 14:46:16 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Type	ScalarConverter::_isInf(std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "inf")
		return (DOUBLE);
	if (str == "-inff" || str == "+inff" || str == "inff")
		return (FLOAT);
	return (NOPE);
}

Type	ScalarConverter::_isNan(std::string &str)
{
	if (str == "nan")
		return (DOUBLE);
	if (str == "nanf")
		return (FLOAT);
	return (NOPE);
}

size_t	ScalarConverter::_findSize(std::string &str)
{
	size_t	leading_zeroes;
	size_t	i = 0;

	if (str.at(0) == '+' || str.at(0) == '-')
		i++;
	for (; i < str.size() - 1; i++)
	{
		if (str.at(i + 1) == '.')
			break ;
		if (str.at(i) != '0')
			break ;
	}
	leading_zeroes = i;
	for (i = leading_zeroes; i != str.size(); i++)
	{
		if (str.at(i) == '.')
			break ;
	}
	return (i - leading_zeroes);
}

bool	ScalarConverter::_isOverflow(Type type, bool negative, int num, std::string &str)
{
	if (type == CHAR && (num < 0 || num > 255))
		return (true);
	if ((num < 0 && !negative) || (num >= 0 && negative))
		return (true);
	if (num < 0)
		num = -num;
	size_t	amount_of_digits = 1;
	int tmp = num;
	while (tmp/10)
	{
		tmp /= 10;
		amount_of_digits++;
	}
	if (amount_of_digits != _findSize(str))
		return (true);
	return (false);
}

bool	ScalarConverter::_weirdInput(std::string &str)
{
	int	comma_count = 0;

	for (size_t i = 0; i != str.size(); i++)
	{
		if (str.at(i) == 'f' && i + 1 == str.size() && comma_count)
			continue ;
		if (i == 0 && (str.at(i) == '+' || str.at(i) == '-'))
			continue ;
		else if (str.at(i) == '.')
		{
			comma_count++;
			if (i == 0 || i + 1 == str.size() || comma_count != 1)
				return (true);
		}
		else if (str.at(i) == ',')
		{
			std::cout << "excel be like:" << std::endl << "    ";
			return (true);
		}
		else if (!isdigit(str.at(i)))
			return (true);
	}
	return (false);
}

Type	ScalarConverter::_detectType(std::string &str)
{
	if (str.empty())
		return (NOPE);
	if (str.size() == 1)
	{
		if (isdigit(str.at(0)))
			return (INT);
		else
			return (CHAR);
	}
	if (_isInf(str) == FLOAT || _isNan(str) == FLOAT)
		return (FLOAT);
	if (_isInf(str) == DOUBLE || _isNan(str) == DOUBLE)
		return (DOUBLE);
	if (_weirdInput(str))
		return (NOPE);
	size_t found = str.find('.');
	if (found == std::string::npos)
		return (INT);
	if (str.back() == 'f')
		return (FLOAT);
	return (DOUBLE);
}

void	ScalarConverter::_charConvert(Type type, std::string &str)
{
	char	c;
	int		num;
	bool	negative = false;

	std::cout << "char: ";
	if (_isInf(str) || _isNan(str))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (type == CHAR)
		num = static_cast<int>(str[0]);	
	else
	{
		if (str.at(0) == '-')
			negative = true;
		num = atoi(str.c_str());
		if (_isOverflow(CHAR, negative, num, str))
		{
			std::cout << "overflow" << std::endl;
			return ;
		}
	}
	c = static_cast<char>(num);
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::_intConvert(Type type, std::string &str)
{
	int		num;
	bool	negative = false;

	std::cout << "int: ";
	if (_isInf(str) || _isNan(str))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (str.at(0) == '-')
		negative = true;
	if (type == CHAR)
		num = static_cast<int>(str[0]);
	else
		num = atoi(str.c_str());
	if (_isOverflow(INT, negative, num, str))
		std::cout << "overflow" << std::endl;
	else
		std::cout << num << std::endl;
}

void	ScalarConverter::_floatConvert(Type type, std::string &str)
{
	float	tmp;
	float	num;

	std::cout << "float: ";
	if (_isInf(str) || _isNan(str))
	{
		std::cout << str;
		if (_isInf(str) == DOUBLE || _isNan(str) == DOUBLE)
			std::cout << "f";
		std::cout << std::endl;
		return ;
	}
	if (type == CHAR)
		num = static_cast<float>(str[0]);
	else
	{
		tmp = atof(str.c_str());
		num = static_cast<float>(tmp);
	}
	if (num - static_cast<int>(num) == 0)
		std::cout << num << ".0f" << std::endl;
	else
		std::cout << num << "f" << std::endl;
}

void	ScalarConverter::_doubleConvert(Type type, std::string &str)
{
	double	tmp;
	double	num;

	std::cout << "double: ";
	if (_isInf(str) || _isNan(str))
	{
		if (_isInf(str) == FLOAT || _isNan(str) == FLOAT)
			str.erase(str.end() - 1);
		std::cout << str << std::endl;
		return ;
	}
	if (type == CHAR)
		num = static_cast<double>(str[0]);
	else
	{
		tmp = atof(str.c_str());
		num = static_cast<double>(tmp);
	}
	if (num - static_cast<int>(num) == 0)
		std::cout << num << ".0" << std::endl;
	else
		std::cout << num << std::endl;
}

void	ScalarConverter::convert(std::string &str)
{
	Type type = _detectType(str);

	if (type == NOPE)
	{
		std::cout << "bruv wtf is that" << std::endl;
		return ;
	}
	else if (type == CHAR)
		std::cout << "[CHAR]" << std::endl;
	else if (type == INT)
		std::cout << "[INT]" << std::endl;
	else if (type == FLOAT)
		std::cout << "[FLOAT]" << std::endl;
	else
		std::cout << "[DOUBLE]" << std::endl;
	_charConvert(type, str);
	_intConvert(type, str);
	_floatConvert(type, str);
	_doubleConvert(type, str);

}
