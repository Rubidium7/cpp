/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamEditor.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:27:29 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/26 21:28:36 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamEditor.hpp"

StreamEditor::StreamEditor(std::string file, std::string s1, std::string s2) : 
		file(file), s1(s1), s2(s2), newFile(file + ".replace")
{}

StreamEditor::~StreamEditor()
{}

void	StreamEditor::you_sed_it_bestie(void)
{
	std::ifstream	input(file);
	std::string		line;

	if (!input.is_open())
	{
		std::cerr << "Errawr 🦖" << std::endl;
		std::cerr << "the opening of input file failed" << std::endl;
		return ;
	}
	std::ofstream	output(newFile);
	if (!output.is_open())
	{
		input.close();
		std::cerr << "Errawr 🦖" << std::endl;
		std::cerr << "the opening of output file failed" << std::endl;
		return ;
	}
	while (getline(input, line))
	   output << process_line(line) << std::endl;
	input.close();
	output.close();
}

std::string StreamEditor::process_line(std::string in_string)
{
	std::string	storage;
	size_t		pos = 0, last_pos = 0;

	while (pos != std::string::npos)
	{
		if ((pos = in_string.find(s1, last_pos)) != std::string::npos)
		{
			if (pos != last_pos)
				storage += in_string.substr(last_pos, pos - last_pos);
			storage += s2;
			pos += s1.length();
			last_pos = pos;
		}
		else
			storage += in_string.substr(last_pos, in_string.length());
	}
	return (storage);
}

