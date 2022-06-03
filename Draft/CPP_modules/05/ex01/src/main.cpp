/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:20:12 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 20:51:21 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat foo("bar", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat foo("bar", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat bar("John", 3);

	std::cout << bar << std::endl;

	try
	{
		for (int i = 0; i < 4; i++)
		{
			bar.increment_grade();
			std::cout << bar << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form("bar", 42, 42);
		Bureaucrat bar("bar", 42);

		std::cout << "Form: " << form << "Bureaucrat: " << bar << std::endl;

		bar.signForm(form);
		std::cout << "Form: " << form << "Bureaucrat: " << bar << std::endl;
		bar.decrement_grade();
		std::cout << "Form: " << form << "Bureaucrat: " << bar << std::endl;
		bar.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

	return (0);
}