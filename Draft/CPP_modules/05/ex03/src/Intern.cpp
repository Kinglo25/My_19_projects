/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:54:44 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 21:02:09 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// ----------------------------- Constructors ------------------------------ //
Intern::Intern()
{
	_INTERN_AUTO(32, "Default Constructor");
}

Intern::Intern(const Intern& c) 
{
	_INTERN_AUTO(32, "Copy Constructor");
	(void)c;
}

// ------------------------------ Destructor ------------------------------- //
Intern::~Intern()
{
	_INTERN_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Intern & Intern::operator=(const Intern& c)
{
	_INTERN_AUTO(32, "Copy Assignement Operator");
	(void)c;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //


// --------------------------------- Methods ------------------------------- //

Form *Intern::makeForm(std::string type, std::string target)
{
    std::string array[3] = {"presidential", "robotomy", "shrubbery"};
	Form *(Intern::*(fct[3]))(std::string) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};

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

Form *Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

Form *Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}
