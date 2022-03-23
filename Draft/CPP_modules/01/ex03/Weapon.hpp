/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:26:21 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/23 16:29:41 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
private:

	std::string		_type;

public:

	Weapon(std::string type);
	~Weapon();

	std::string const&	get_type() const;
	void				set_type(std::string type);
};

#endif