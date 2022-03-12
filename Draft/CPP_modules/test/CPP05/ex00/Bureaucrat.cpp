/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:43:56 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:55:10 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors & Destructors
Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade())
{
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

//operator overload
Bureaucrat &Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src.getGrade();
	return (*this);
}

std::ostream &operator<<( std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << " bureaucrat grade " << i.getGrade();
	return (o);
}

//exception
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("'s grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("'s grade is too low.");
}

//Accessors
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//Actions
void	Bureaucrat::incGrade()
{
	try {
		this->_grade--;
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

void	Bureaucrat::decGrade()
{
	try {
		this->_grade++;
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}
