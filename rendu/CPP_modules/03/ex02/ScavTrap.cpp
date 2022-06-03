/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:09:42 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 00:18:00 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
		: ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
				: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hp = 100;	
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
			: ClapTrap(cpy)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap has entered Gate keeper mode" << std::endl;
}