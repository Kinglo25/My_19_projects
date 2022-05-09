/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:50 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 16:27:34 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
		: Animal("Brain")
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(std::string type)
{
	std::cout << "Typing Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& cpy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	this->type_ = cpy.get_type();
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain Assignment operator called" << std::endl;
	this->type_ = rhs.get_type();
	return (*this);
}

void		Brain::makeSound() const
{
	std::cout << "Miiiaaaou" << std::endl;
}