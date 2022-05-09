/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:30:44 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 00:34:27 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
		: ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
				: ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hp = 100;	
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy)
			: ClapTrap(cpy)
{
	std::cout << "Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap wants to high fives!" << std::endl;
}