/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:47:04 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 15:47:35 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
		: WrongAnimal("WrongCat")
{
	this->_brain = new Brain();
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
				: WrongAnimal(type)
{
	this->_brain = new Brain();
	std::cout << "Typing WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat Assignment operator called" << std::endl;
	this->_type = rhs.get_type();
	this->_brain = new Brain();
	*this->_brain = *rhs._brain;
	return (*this);
}

void		WrongCat::makeSound() const
{
	std::cout << "Miiiaaaou" << std::endl;
}