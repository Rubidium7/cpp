/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamEditor.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:21:23 by nlonka            #+#    #+#             */
/*   Updated: 2023/05/26 13:51:41 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAMEDITOR_HPP
# define STREAMEDITOR_HPP

# include <iostream>
# include <fstream>
# include <string>

class StreamEditor
{
	public:
		StreamEditor(std::string file, std::string s1, std::string s2);
		~StreamEditor();
		void	you_sed_it_bestie();

	private:
		std::string	file;
		std::string	s1;
		std::string	s2;
		std::string	newFile;
		std::string	process_line(std::string line);
};

#endif
