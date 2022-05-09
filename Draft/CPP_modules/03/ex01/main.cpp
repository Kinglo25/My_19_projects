/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:40:13 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 00:28:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("SC4V-TP");

	a.attack("Hyperion");
	a.beRepaired(3);
	a.takeDamage(5);
	a.beRepaired(2);
	a.beRepaired(42);
	a.takeDamage(420);
	a.attack("randomPeople");
	a.beRepaired(5);
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.guardGate();
	return (0);
}