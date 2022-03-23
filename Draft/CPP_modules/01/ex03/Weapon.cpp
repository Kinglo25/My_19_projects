/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:26:24 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 22:03:56 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::~Weapon()
{

}

std::string&	Weapon::get_type() const
{
	return (&this->_type);
}

void			Weapon::set_type(std::string type)
{
	this->_type = type;
}