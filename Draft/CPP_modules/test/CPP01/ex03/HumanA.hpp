/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:12:11 by jandre            #+#    #+#             */
/*   Updated: 2021/08/17 16:04:54 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
# define HUMAN_A
# include "Weapon.hpp"

class HumanA
{
    private:
    std::string name;
    Weapon      &weapon;
    
    public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);

    void    attack(void);
    void    setWeapon(Weapon &weapon);

};

#endif