/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:26:51 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 14:26:42 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap guy1("Guy");
    ClapTrap guy2("Raymond");
    ClapTrap guy3;
    ClapTrap guy4(guy1);

    std::cout << std::endl << "Test with the basic values" << std::endl;
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl << "Changing attack value and trying to kill one guy and attacking him once dead" << std::endl;
    guy1.set_attackdmg(5);
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl << "Healing the dead guy and attacking him again" << std::endl;
    guy2.beRepaired(10);
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl << "Just healing a guy to see what it does" << std::endl;
    guy2.beRepaired(5);
    guy2.beRepaired(5);
    guy2.beRepaired(5);
    guy2.beRepaired(5);
    guy1.attack("Raymond");
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl;
    return (0);
}