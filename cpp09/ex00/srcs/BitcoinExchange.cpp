/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:30:34 by nlonka            #+#    #+#             */
/*   Updated: 2023/11/16 18:55:10 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::_checkDate(std::string date)
{
	if (date.size() != 10)
		return (true);
	for (size_t i = 0; i != 10; i++)
	{
		if ((i == 4 || i == 7 ) && date.at(i) == '-')
			;
		else if (!isdigit(date.at(i)))
			return (true);
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (true);
	if (day == 31 && month != 1 && month != 3 && month != 5 && month != 7
			&& month != 8 && month != 10 && month != 12)
		return (true);
	if (month == 2 && day == 30)
		return (true);
	if (month == 2 && day == 29 && year % 4 != 0)
		return (true);
	return (false);
}

bool	BitcoinExchange::_checkNum(std::string rate)
{
	bool dot = false;
	for (size_t i = 0; i != rate.size(); i++)
	{
		if (rate.at(i) == '.' && dot)
			return (true);
		if (rate.at(i) == '.' && (!i || i + 1 == rate.size()))
			return (true);
		if (rate.at(i) == '.')
			dot = true;
		else if (!isdigit(rate.at(i)))
			return (true);
	}
	return (false);
}

bool	BitcoinExchange::_insertToDataBase(std::string date, std::string rate)
{
	if (date.empty() || rate.empty())
		return (true);
	if (_checkDate(date))
		return (true);	
	if (_checkNum(rate))
		return (true);
	_db[date] = atof(rate.c_str());
	return (false);
}


bool	BitcoinExchange::_safeDataBase(std::ifstream &file)
{
	std::string tmp;

	if (!file.good())
		return (true);
	getline(file, tmp);
	if (tmp != "date,exchange_rate")
		return (true);
	while (file.good())
	{
		getline(file, tmp);
		if (tmp.empty() && file.eof())
			break ;
		size_t comma = tmp.find(',');
		if (!comma || comma == std::string::npos || comma == tmp.size() - 1)
			return (true);
		if (_insertToDataBase(tmp.substr(0, comma), tmp.substr(comma + 1, std::string::npos)))
			return (true);
	}
	return (false);
}

BitcoinExchange::BitcoinExchange(std::string infile, std::string db_file) : _infile(infile)
{
	if (!_infile.is_open())
	{
		std::cout << "Error: couldn't open \"" << infile << "\"" << std::endl;
		throw std::exception();
	}
	std::ifstream file(db_file);

	if (!file.is_open())
	{
		_infile.close();
		std::cout << "Error: couldn't open \"" << db_file << "\"" << std::endl;
		throw std::exception();
	}
	if (_safeDataBase(file))
	{
		_infile.close();
		file.close();
		std::cout << "Error: data file corrupted" << std::endl;
		throw std::exception();
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	_db = rhs._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	_infile.close();
}

void	BitcoinExchange::_badInput(std::string complaint)
{
	std::cout << "Error: bad input => " << complaint << std::endl;
}

bool	BitcoinExchange::_checkAmount(std::string amount)
{
	if (amount.at(0) == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (true);
	}
	if (amount.at(0) == '+')
	{
		std::cout << "Error: I find plus signs perturbing, please remove them." << std::endl;
		return (true);
	}
	if (_checkNum(amount))
	{
		std::cout << "Error: number bad >:(" << std::endl;
		return (true);
	}
	float num = atof(amount.c_str());
	if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (true);
	}
	return (false);
}

void	BitcoinExchange::_processLine(std::string &line)
{
	std::string date;
	std::string value;

	if (line.empty())
		return ;
	line.erase(line.end()--);
	if (line.size() < 14)
		return (_badInput(line));
	if (line.at(10) != ' ' || line.at(11) != '|' || line.at(12) != ' ')
		return (_badInput(line));
	date = line.substr(0, 10);
	if (_checkDate(date))
		return (_badInput(date));
	value = line.substr(13, std::string::npos);
	if (_checkAmount(value))
		return ;
	std::map<std::string, float>::iterator it = _db.lower_bound(date);
	if (it == _db.begin() && it->first > date)
	{
		std::cout << "Error: the date is before the dates in the database => " << date << std::endl;
		return ;
	}
	if (it->first != date)
		it--;
	float rate = it->second;
	float res = rate * atof(value.c_str());
	std::cout << date << " => " << value;
	std::cout << " = " << res << std::endl;
}

void	BitcoinExchange::printRates()
{
	std::string	line;

	if (!_infile.good())
		return ;
	getline(_infile, line);
	if (line != "date | value")
	{
		std::cout << "Error: first line of input file needs to be \"date | value\"" << std::endl;
		return ;
	}
	while (_infile.good())
	{
		getline(_infile, line);
		_processLine(line);
	}
}

void	BitcoinExchange::_printData()
{
	std::map<std::string, float>::iterator it = _db.begin();

	std::cout << std::setprecision(7);
	while (it != _db.end())
	{
		std::cout << it->first << "," << it->second << std::endl;
		it++;
	}

}
