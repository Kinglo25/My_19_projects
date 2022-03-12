/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:33:09 by jandre            #+#    #+#             */
/*   Updated: 2021/08/10 17:54:50 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  lolo[5];
    Zombie  *zmb = newZombie("Octave");
    int     i;

    i = -1;
    std::cout << "Zombies on the stack announce themselves:" << std::endl;
    while (++i < 5)
        lolo[i].announce();
    std::cout << std::endl << "Now the zombies on the heap:" << std::endl;
    zmb->announce();
    randomChump("Marcelus the third");
    delete zmb;
    return (0);
}