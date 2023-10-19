/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:45:02 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/19 14:46:13 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <limits>
# include <cctype>
# include <string>
# include <iostream>
# include <iomanip>

enum Type
{
	NOPE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	public:
		static void convert(std::string &str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &rhs);

		static Type	_isInf(std::string &str);
		static Type	_isNan(std::string &str);
		static size_t _findSize(std::string &str);
		static bool	_isOverflow(Type type, bool negative, int num, std::string &str);
		static bool	_weirdInput(std::string &str);
		static Type	_detectType(std::string &str);

		static void	_charConvert(Type type, std::string &str);
		static void	_intConvert(Type type, std::string &str);
		static void	_floatConvert(Type type, std::string &str);
		static void	_doubleConvert(Type type, std::string &str);
};

#endif
