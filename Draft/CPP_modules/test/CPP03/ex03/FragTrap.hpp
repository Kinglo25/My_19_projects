/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:21:07 by jandre            #+#    #+#             */
/*   Updated: 2021/11/23 12:06:39 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
# define FRAGTRAP
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
    public:
        //Constructors & Destructors
        FragTrap(void);
        FragTrap(const FragTrap &src);
        FragTrap(std::string name);
        ~FragTrap(void);
        
        //opperators
        FragTrap   &operator=(const FragTrap &rhs);

        //action
        void highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &out, const FragTrap &in);

#endif