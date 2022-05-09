/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:26:31 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/14 16:45:05 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:

	std::string	_name;
	Weapon*		_weapon;

public:

	HumanB(std::string name);
	~HumanB();

	void	set_weapon(Weapon& weapon);
	void	attack();
};

#endif