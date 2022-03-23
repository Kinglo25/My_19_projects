/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:26:26 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/23 16:08:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:

	std::string	_name;
	Weapon&		_weapon;

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void	attack();

};

#endif