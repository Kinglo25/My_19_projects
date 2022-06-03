/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:39 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 16:32:01 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
		: Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(std::string type)
				: Animal(type)
{
	this->_brain = new Brain();
	std::cout << "Typing Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& cpy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	this->_type = rhs.get_type();
	this->_brain = new Brain();
	*this->_brain = *rhs._brain;
	return (*this);
}

void		Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

void		Dog::set_idea(size_t i, std::string idea)
{
	this->_brain->set_idea(i, idea);
}

const std::string	Dog::get_idea(size_t i)
{
	return (this->_brain->get_idea(i));
}