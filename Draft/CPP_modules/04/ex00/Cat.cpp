/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:37 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 15:14:40 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
		: Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(std::string type)
				: Animal(type)
{
	std::cout << "Typing Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cpy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type_ = cpy.get_type();
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	this->type_ = rhs.get_type();
	return (*this);
}

void		Cat::makeSound() const
{
	std::cout << "Miiiaaaou" << std::endl;
}