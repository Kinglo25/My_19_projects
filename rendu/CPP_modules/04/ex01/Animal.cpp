/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:35 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 17:01:07 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
				: _type(type)
{
	std::cout << "Typing Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& cpy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = cpy.get_type();
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal Assignment operator called" << std::endl;
	this->_type = rhs.get_type();
	return (*this);
}

std::string	Animal::get_type() const
{
	return (this->_type);
}

void		Animal::set_type(std::string const type)
{
	this->_type = type;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}