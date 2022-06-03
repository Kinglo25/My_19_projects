/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:40:13 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/19 17:52:32 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("CL4P-TP");

	a.attack("Hyperion");
	a.beRepaired(3);
	a.takeDamage(5);
	a.beRepaired(2);
	a.beRepaired(42);
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.attack("la personne qui me corrige si elle me met faux");
	a.takeDamage(42);
	a.attack("randomPeople");
	a.beRepaired(5);
	return (0);
}