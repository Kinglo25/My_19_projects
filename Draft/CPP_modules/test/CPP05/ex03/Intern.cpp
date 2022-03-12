/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:57:03 by jandre            #+#    #+#             */
/*   Updated: 2022/01/31 16:56:21 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Constructor & Destructor
Intern::Intern()
{
    return ;
}

Intern::Intern(Intern const &src)
{
    *this = src;
    return ;
}

Intern::~Intern()
{
    return ;
}

//operator overload
Intern &Intern::operator=(Intern const & src)
{
    (void)src;
	return (*this);
}

//Action
AForm *Intern::makeForm(std::string type, std::string target)
{
    std::string array[3] = {"presidential", "robotomy", "shrubbery"};
	AForm *(Intern::*(fct[3]))(std::string) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (type == array[i])
		{
			std::cout << "Intern creates <" << type << ">." << std::endl;
			return (((this)->*(fct[i]))(target));
		}
	}
    return (NULL);
}

AForm *Intern::createPresidential(std::string target) {
	return new PresidentialForm(target);
}

AForm *Intern::createRobotomy(std::string target) {
	return new RobotomyForm(target);
}

AForm *Intern::createShrubbery(std::string target) {
	return new ShrubberyForm(target);
}