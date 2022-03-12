/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:26:51 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 15:10:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap guy1("Guy");
    ClapTrap guy2("Raymond");
    ClapTrap guy3;
    ClapTrap guy4(guy1);
    ScavTrap guy5("Marcelo");
    ScavTrap guy6("Bibo");
    ScavTrap guy7;
    ScavTrap guy8(guy5);

    std::cout << std::endl << "Test with the basic values for CLAPTRAP" << std::endl;
    guy1.attack(guy2.get_name());
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl << "Test with the basic values for SCAVTRAP" << std::endl;
    guy5.attack(guy6.get_name());
    guy6.takeDamage(guy5.get_attackdmg());
    std::cout << std::endl << "Changing attack value and trying to kill one guy and attacking him once dead for CLAPTRAP" << std::endl;
    guy1.set_attackdmg(5);
    guy1.attack(guy2.get_name());
    guy2.takeDamage(guy1.get_attackdmg());
    guy1.attack(guy2.get_name());
    guy2.takeDamage(guy1.get_attackdmg());
    guy1.attack(guy2.get_name());
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl << "Changing attack value and trying to kill one guy and attacking him once dead for SCAVTRAP" << std::endl;
    guy5.set_attackdmg(40);
    guy6.attack(guy6.get_name());
    guy6.takeDamage(guy5.get_attackdmg());
    guy5.attack(guy6.get_name());
    guy6.takeDamage(guy5.get_attackdmg());
    guy5.attack(guy6.get_name());
    guy6.takeDamage(guy5.get_attackdmg());
    std::cout << std::endl << "Healing the dead guy and attacking him again for CLAPTRAP" << std::endl;
    guy2.beRepaired(10);
    guy1.attack(guy2.get_name());
    guy2.takeDamage(guy1.get_attackdmg());
    guy1.attack(guy2.get_name());
    guy2.takeDamage(guy1.get_attackdmg());
    std::cout << std::endl << "Healing the dead guy and attacking him again for SCAVTRAP" << std::endl;
    guy6.beRepaired(80);
    guy5.attack(guy6.get_name());
    guy6.takeDamage(guy5.get_attackdmg());
    guy5.attack(guy6.get_name());
    guy6.takeDamage(guy5.get_attackdmg());
    std::cout << std::endl << "Testing gatekeeper mode" << std::endl;
    guy5.guardGate();
    guy6.guardGate();
    guy7.guardGate();
    guy8.guardGate();
    std::cout << std::endl << "Exiting gatekeeper mode" << std::endl;
    guy5.guardGate();
    guy6.guardGate();
    guy7.guardGate();
    guy8.guardGate();
    std::cout << std::endl;
    return (0);
}