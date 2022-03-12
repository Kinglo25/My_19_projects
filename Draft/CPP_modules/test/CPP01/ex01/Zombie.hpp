/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:33:23 by jandre            #+#    #+#             */
/*   Updated: 2021/08/12 20:14:58 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# define SIZE 10
# include <iostream>
# include <cstdlib>
# include <string>

class Zombie
{
    public:
    Zombie(void);
    ~Zombie(void);

    void    announce(void);
    void    name_me(std::string new_name);
    
    private:
    std::string name;

};

Zombie* zombieHorde(int N, std::string name);

#endif