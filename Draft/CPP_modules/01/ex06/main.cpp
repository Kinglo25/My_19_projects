/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:50:10 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/06 16:50:13 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	check_complaint(std::string complaint)
{
	if (complaint == "DEBUG")
		return (1);
	else if (complaint == "INFO")
		return (2);
	else if (complaint == "WARNING")
		return (3);
	else if (complaint == "ERROR")
		return (4);
	else
		return (0);
}

int	main(int ac, char **av)
{
	Harl		Karen;
	
	if (ac != 2)
	{
		std::cout 	<< "I need one argument to complain!!" << std::endl;
		return (0);
	}
	switch (check_complaint(av[1]))
	{
		case DEBUG:
			Karen.complain("DEBUG");
		case INFO:
			Karen.complain("INFO");
		case WARNING:
			Karen.complain("WARNING");
		case ERROR:
			Karen.complain("ERROR");
			break ;
		default:
			std::cout << "Don't be like Harl/Karen" << std::endl;
			break;
	}
	return (0);
}
