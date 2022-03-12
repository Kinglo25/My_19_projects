/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:11:44 by jandre            #+#    #+#             */
/*   Updated: 2021/08/10 18:15:08 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    int     i;

    zombie = zombieHorde(SIZE, "Lolo");
    i = 0;
    while (i < SIZE)
    {
        zombie[i].announce();
        i++;
    }
    delete [] zombie;
}