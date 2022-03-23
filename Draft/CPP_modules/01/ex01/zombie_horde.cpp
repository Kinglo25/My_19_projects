/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_horde.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:10:05 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 20:41:37 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombie_horde( int N, std::string name )
{
	Zombie* ZombabiesHorde = new Zombie[N];

	while (N--)
	{
		ZombabiesHorde[N].set_name(name);
		ZombabiesHorde[N].announce();
	}
	return (ZombabiesHorde);
}