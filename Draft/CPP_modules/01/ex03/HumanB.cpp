/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:26:34 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/23 17:16:50 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
				: _name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::set_weapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	std::string const&	weapon_type =  _weapon->get_type();

	std::cout	<< this->_name << " attacks with their " 
				<< weapon_type << std::endl
				;
}
