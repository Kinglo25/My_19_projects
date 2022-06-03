/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:37 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 16:31:59 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
		: Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(std::string type)
				: Animal(type)
{
	this->_brain = new Brain();
	std::cout << "Typing Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cpy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	this->_type = rhs._type;
	this->_brain = new Brain();
	*this->_brain = *rhs._brain;
	return (*this);
}

void		Cat::makeSound() const
{
	std::cout << "Miiiaaaou" << std::endl;
}

void		Cat::set_idea(size_t i, std::string idea)
{
	this->_brain->set_idea(i, idea);
}

const std::string	Cat::get_idea(size_t i)
{
	return (this->_brain->get_idea(i));
}