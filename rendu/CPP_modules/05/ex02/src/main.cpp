/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:20:12 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 20:51:05 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	{
		ShrubberyCreationForm form("Mara");
		Bureaucrat bar("bar", 145);

		std::cout << "Form: " << form << "Bureaucrat: " << bar << std::endl;

		bar.signForm(form);
		bar.executeForm(form);
		for (int i = 0; i < 8; i++)
		{
			bar.increment_grade();
		}
		std::cout << "Bureaucrat: " << bar << std::endl;
		bar.executeForm(form);
		bar.decrement_grade();
		bar.executeForm(form);
	}

	{
		RobotomyRequestForm form("Franky");
		Bureaucrat bar("bar", 72);

		bar.signForm(form);
		for (int i = 0; i < 27; i++)
		{
			bar.increment_grade();
		}
		std::cout << "Bureaucrat: " << bar << std::endl;
		for (int i = 0; i < 5; i++)
		{
			bar.executeForm(form);
		}
		bar.decrement_grade();
		bar.executeForm(form);
	}

	{
		PresidentialPardonForm form("ShoeGuy");
		Bureaucrat bar("bar", 25);

		std::cout << "Form: " << form << "Bureaucrat: " << bar << std::endl;

		bar.signForm(form);
		for (int i = 0; i < 20; i++)
		{
			bar.increment_grade();
		}
		std::cout << "Bureaucrat: " << bar << std::endl;
		bar.executeForm(form);
		bar.decrement_grade();
		bar.executeForm(form);
	}

	return (0);
}