/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:26:44 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 16:25:05 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructors & Destructors
ClapTrap::ClapTrap(void) : name("NO_NAME"), hitpoints(10), energy(10), attackdmg(0)
{
    std::cout << "Mister " << name << " created" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energy(10), attackdmg(0)
{
    std::cout << "Mister " << name << " created" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
    std::cout << "Mister " << name << " created" << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called for " << this->name << std::endl;
    return ;
}

//accessors

void    ClapTrap::set_attackdmg(int const new_value)
{
    this->attackdmg = new_value;
    return ;
}

void    ClapTrap::set_energy(int const new_value)
{
    this->energy = new_value;
    return ;
}

void    ClapTrap::set_hitpoints(int const new_value)
{
    this->hitpoints = new_value;
    return ;
}

void    ClapTrap::set_name(std::string const new_name)
{
    this->name = new_name;
    return ;
}

std::string ClapTrap::get_name(void) const
{
    return (this->name);
}

int ClapTrap::get_attackdmg(void) const
{
    return(this->attackdmg);
}

int ClapTrap::get_energy(void) const
{
    return(this->energy);
}

int ClapTrap::get_hitpoints(void) const
{
    return (this->hitpoints);
}

//operators
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this != &rhs)
    {
        this->set_name(rhs.get_name());
        this->set_attackdmg(rhs.get_attackdmg());
        this->set_energy(rhs.get_energy());
        this->set_hitpoints(rhs.get_hitpoints());
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &in)
{
    out << in.get_name();
    return (out);
}

//Actions

void ClapTrap::attack(std::string const &target)
{
    if (this->hitpoints > 0)
    {
        if (this->energy > 0)
        {
            this->energy--;
            std::cout << this->name << " attacks " << target << " causing " << this->attackdmg << " damages" << std::endl;
        }
        else
            std::cout << this->name << " doesn't have enough energy to attack anyone..." << std::endl;
    }
    else
        std::cout << this->name << " is dead and can't attack anyone..." << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitpoints > 0)
    {
        std::cout << this->name << " received " << amount << " damages" << std::endl;
        this->hitpoints -= amount;
        if (this->hitpoints <= 0)
        {
            this->hitpoints = 0;
            std::cout << this->name << " received too much damages and died!" << std::endl;
        }
        else
            std::cout << this->name << " has " << this->hitpoints << " hitpoints left" << std::endl;
    }
    else
        std::cout << this->name << " is already dead and can't take more damage..." << std::endl;
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitpoints <= 0)
    {
        this->hitpoints += amount;
        std::cout << this->name << " was ressucitated and is now left with " << amount << " hitpoints!! MIRACLE" << std::endl;
        return ;
    }
    std::cout << this->name << " is healed of " << amount << " hitpoint" << std::endl;
    this->hitpoints += amount;
    std::cout << this->name << " now has " << this->hitpoints << " left" << std::endl;
    return ;
}