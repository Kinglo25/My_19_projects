/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:52:44 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 20:47:14 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie* ZombieHorde;

	(void)ac;
	ZombieHorde = zombie_horde(atoi(av[1]), av[2]);
	delete [] ZombieHorde;
}