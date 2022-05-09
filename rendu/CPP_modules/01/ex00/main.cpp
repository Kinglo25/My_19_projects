/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:52:44 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 19:45:31 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie0;

	Zombie0 = newZombie("George");
	Zombie0->announce();
	randomChump("Lucas");
	delete(Zombie0);
	return (0);
}