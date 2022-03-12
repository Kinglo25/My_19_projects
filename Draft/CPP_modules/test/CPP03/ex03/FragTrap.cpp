/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:20:57 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 16:30:40 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Constructors & Destructors
FragTrap::FragTrap(void)
{
    this->name = "NO_NAME";
    this->hitpoints = 100;
    this->energy = 100;
    this->attackdmg = 30;
    std::cout << "[FRAGTRAP] Mister " << name << " created" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hitpoints = 100;
    this->energy = 100;
    this->attackdmg = 30;
    std::cout << "[FRAGTRAP] Mister " << name << " created" << std::endl;
    return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
    *this = src;
    std::cout << "[FRAGTRAP] Mister " << name << " created" << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "[FRAGTRAP] Destructor called for " << this->name << std::endl;
    return ;
}

//operator

FragTrap &FragTrap::operator=(const FragTrap &rhs)
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

std::ostream &operator<<(std::ostream &out, const FragTrap &in)
{
    out << in.get_name();
    return (out);
}

//actions

void FragTrap::highFivesGuys(void)
{
    std::string ans;

    ans = "nothing yet";
    std::cout << this->name << " wants to do a HIGHFIVE with you, do you want to? [YES/NO]" << std::endl;
    
    while (ans != "YES" && ans != "NO")
    {
        std::cin >> ans;
        if (ans == "YES")
            std::cout << "Yay lets go for a HIGHFIVE! **CLAP**" << std::endl;
        else if (ans == "NO")
            std::cout << "Pfff no fun at all...." << std::endl;
        else
            std::cout << "Man i am really dumb please answer me something that i understand... [YES/NO]" << std::endl;
    }
    return ;
}