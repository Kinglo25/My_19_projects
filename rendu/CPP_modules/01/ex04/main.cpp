/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:34:30 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/14 19:56:00 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void	ft_replace(std::ifstream& input, std::ofstream& output, std::string s1, std::string s2)
{
	std::string	buffer;
	std::size_t	found;

	while (getline(input, buffer))
	{
		while ((found = buffer.find(s1)) != std::string::npos)
		{
			buffer.erase(found, s1.length());
			buffer.insert(found, s2);
		}
		output << buffer << std::endl;
	}
	return ;
}

int	main(int ac, char **av)
{
	std::string	infile;

	if (ac != 4)
	{
		std::cout << "Usage: ./ImNoLoser <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (!av[1] || !av[2])
	{
		std::cout << "Strings provided can't be empty!" << std::endl;
		return (1);
	}
	infile = av[1];
	std::ifstream input(infile);
	std::ofstream output(infile += ".replace");
	if (input.is_open() && output.is_open())
		ft_replace(input, output, av[2], av[3]);
	else 
		std::cout << "Unable to open file" << std::endl;
	return (0);
}