/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:40:08 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/19 18:25:53 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
				: _name(name), _hp(10), _ep(10), _ad(19)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy)
			:_name(cpy._name), _hp(cpy._hp), _ep(cpy._ep), _ad(cpy._ad)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	this->_name = rhs._name;
	this->_hp = rhs._hp;	
	this->_ep = rhs._ep;
	this->_ad = rhs._ad;
	return (*this);
}

void 	ClapTrap::attack(const std::string& target)
{
	if (!this->_hp)
	{
		std::cout	<< "ClapTrap " << this->_name << " is dead!"
					<< std::endl;
	}
	else if (this->_ep > 0)
	{
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_ad << " damage points!"
					<< std::endl;
		this->_ep--;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->_name << " is exhausted!"
					<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hp)
	{
		std::cout	<< "ClapTrap " << this->_name << " is already dead!"
					<< std::endl;
	}
	else if (this->_hp <= amount)
	{
		this->_hp = 0;
		std::cout	<< "ClapTrap " << this->_name << " lost all his hp"
					<< std::endl;
	}
	else if (this->_hp > 0)
	{
		this->_hp -= amount;
		std::cout	<< "ClapTrap " << this->_name << " lost " << amount
					<< " hp, he has now: " << this->_hp << " hp"
					<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hp)
	{
		std::cout	<< "ClapTrap " << this->_name << " is dead!"
					<< std::endl;
	}
	else if ((this->_hp + amount) > 100 && this->_hp < 100)
	{
		this->_hp = 100;
		std::cout	<< "ClapTrap " << this->_name << " healed all his hp"
					<< std::endl;
		this->_ep--;
	}
	else if (this->_hp < 100)
	{
		this->_hp += amount;
		std::cout	<< "ClapTrap " << this->_name << " healed " << amount
					<< " hp, he has now: " << this->_hp << " hp"
					<< std::endl;
		this->_ep--;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->_name << " is already full life!"
					<< std::endl;
	}
}