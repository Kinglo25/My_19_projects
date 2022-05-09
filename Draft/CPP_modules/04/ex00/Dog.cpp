/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:39 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 15:12:18 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
		: Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(std::string type)
				: Animal(type)
{
	std::cout << "Typing Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& cpy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type_ = cpy.get_type();
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	this->type_ = rhs.get_type();
	return (*this);
}

void		Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
