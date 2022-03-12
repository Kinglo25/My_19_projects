/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:13:14 by jandre            #+#    #+#             */
/*   Updated: 2021/08/17 16:07:02 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
# define WEAPON
# include <iostream>

class Weapon
{
    private:
    std::string type;
    
    public:
    Weapon(std::string type);
    ~Weapon(void);

    void        setType(std::string type);
    std::string &getType(void);
};

#endif