/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:47:04 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 15:49:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
		: WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
				: WrongAnimal(type)
{
	std::cout << "Typing WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->type_ = cpy.get_type();
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat Assignment operator called" << std::endl;
	this->type_ = rhs.get_type();
	return (*this);
}

void		WrongCat::makeSound() const
{
	std::cout << "Miiiaaaou" << std::endl;
}