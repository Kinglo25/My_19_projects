/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:09:42 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/16 18:48:17 by lmajerus         ###   ########.fr       */
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

void 	ScavTrap::attack(const std::string& target)
{
	if (!this->_hp)
	{
		std::cout	<< "ScavTrap " << this->_name << " is dead!"
					<< std::endl;
	}
	else if (this->_ep > 0)
	{
		std::cout	<< "ScavTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_ad << " damage points!"
					<< std::endl;
		this->_ep--;
	}
	else
	{
		std::cout	<< "ScavTrap " << this->_name << " is exhausted!"
					<< std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap has entered Gate keeper mode" << std::endl;
}