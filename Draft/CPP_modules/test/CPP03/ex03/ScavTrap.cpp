/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:29:38 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 16:28:28 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Constructors & Destructors
ScavTrap::ScavTrap(void)
{
    this->name = "NO_NAME";
    this->hitpoints = 100;
    this->energy = 50;
    this->attackdmg = 20;
    this->guardkeeper_mode = 0;
    std::cout << "[SCAVTRAP] Mister " << name << " created" << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hitpoints = 100;
    this->energy = 50;
    this->attackdmg = 20;
    std::cout << "[SCAVTRAP] Mister " << name << " created" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
    *this = src;
    std::cout << "[SCAVTRAP] Mister " << name << " created" << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "[SCAVTRAP] Destructor called for " << this->name << std::endl;
    return ;
}

//operator

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
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

std::ostream &operator<<(std::ostream &out, const ScavTrap &in)
{
    out << in.get_name();
    return (out);
}

//accessors

bool ScavTrap::get_guardGate(void) const
{
    return ((this->guardkeeper_mode));
}

//actions

void ScavTrap::guardGate(void)
{
    if (this->hitpoints > 0)
    {
        if (this->guardkeeper_mode == 0)
        {
            this->guardkeeper_mode = 1;
            std::cout << this->name << " has now entered the Gate Keeper mode be carefull" << std::endl;
        }
        else
        {
            this->guardkeeper_mode = 0;
            std::cout << this->name << " has now exited the Gate Keeper mode, you can be relieved" << std::endl;
        }
    }
    else
        std::cout << "Unfortunately, " << this->name << " is dead and can't enter Gate Keeper mode..." << std::endl;
    return ;
}