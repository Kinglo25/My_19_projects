/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:46:08 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 15:31:16 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
				: _type(type)
{
	std::cout << "Typing WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->_type = cpy.get_type();
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Assignment operator called" << std::endl;
	this->_type = rhs.get_type();
	return (*this);
}

std::string	WrongAnimal::get_type() const
{
	return (this->_type);
}

void		WrongAnimal::set_type(std::string const type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Blip Blop I'm a robot" << std::endl;
}