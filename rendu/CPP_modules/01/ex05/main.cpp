/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:45:31 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/06 16:46:34 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		Karen;
	std::string	level;
	
	(void)av;
	if (ac != 1)
	{
		std::cout 	<< "I don't need arguments to complain!!" << std::endl;
		return (1);
	}
	else
		std::cout 	<< "Hello Do you know Harl? We all do, "
					<< "don't we? In case you don’t, find below "
					<< "the kind of comments Harl makes. "
					<< "They are classified by levels"
					<< std::endl;
	while (true)
	{
		std::cout	<< "You can choose between: DEBUG, INFO, WARNING, ERROR. Please enter a level: ";
		std::cin 	>> level;
		Karen.complain(level);
	}
	return (0);
}
