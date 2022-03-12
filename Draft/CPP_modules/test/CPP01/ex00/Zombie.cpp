/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:33:20 by jandre            #+#    #+#             */
/*   Updated: 2021/08/10 17:05:47 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string names[10] = { "Filou", "Bobo", "Max", "Grominet", "Titi", "Rodriguo", "Marcel", "Abdel", "Josh", "Paul" };

Zombie::Zombie(void)
{
    Zombie::name = names[rand()%10];
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "<Destructor> "<< this->name << " is saying Bye Bye because he is dead..." << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << "<" << this->name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void    Zombie::name_me(std::string new_name)
{
    this->name = new_name;
    return ;
}