/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:50 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 16:01:48 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& cpy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 100; i++)
	{
		if (rhs._ideas[i].length() > 0)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

const std::string	Brain::get_idea(size_t i) const
{
	return (this->_ideas[i]);
}

void	Brain::set_idea(size_t i, std::string idea)
{
	this->_ideas[i] = idea;
}