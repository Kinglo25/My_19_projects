/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:26:24 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/23 16:33:44 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
				: _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const&	Weapon::get_type() const
{
	return (this->_type);
}

void			Weapon::set_type(std::string type)
{
	this->_type = type;
}
