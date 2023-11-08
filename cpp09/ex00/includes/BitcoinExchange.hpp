/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:49 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/08 11:26:00 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string infile, std::string db_file);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void	printRates();

	private:
		BitcoinExchange();
		bool	_checkDate(std::string date);
		bool	_checkNum(std::string rate);
		void	_badInput(std::string complaint);
		bool	_checkAmount(std::string amount);
		void	_processLine(std::string &line);
		bool	_insertToDataBase(std::string date, std::string rate);
		bool	_safeDataBase(std::ifstream &file);
		void	_printData();
		std::map<std::string, float>	_db;
		std::ifstream 				_infile;
	
};

#endif
