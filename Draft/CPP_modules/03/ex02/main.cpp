/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:40:13 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 00:42:35 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	a("SC4V-TP");
	FragTrap	b("FR4G-TP");

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
	b.attack("Hyperion");
	b.beRepaired(3);
	b.takeDamage(5);
	b.beRepaired(2);
	b.beRepaired(42);
	b.takeDamage(420);
	b.attack("randomPeople");
	b.beRepaired(5);
	b.attack("la personne qui me corrige si elle me met faux");
	b.attack("la personne qui me corrige si elle me met faux");
	b.attack("la personne qui me corrige si elle me met faux");
	b.attack("la personne qui me corrige si elle me met faux");
	b.attack("la personne qui me corrige si elle me met faux");
	b.attack("la personne qui me corrige si elle me met faux");
	b.attack("la personne qui me corrige si elle me met faux");
	b.highFivesGuys();
	return (0);
}