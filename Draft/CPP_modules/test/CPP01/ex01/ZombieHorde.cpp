/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:02:42 by jandre            #+#    #+#             */
/*   Updated: 2021/08/10 18:14:01 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zmb = new Zombie[N];
    int i;

    i = 0;
    while (i < N)
    {
        zmb[i].name_me(name);
        i++;
    }
    return (zmb);
}