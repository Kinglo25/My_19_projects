/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:23:20 by jandre            #+#    #+#             */
/*   Updated: 2021/11/23 12:06:45 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP
# define SCAVTRAP
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
    protected:
        bool guardkeeper_mode;
    public:
        //Constructors & Destructors
        ScavTrap(void);
        ScavTrap(const ScavTrap &src);
        ScavTrap(std::string name);
        ~ScavTrap(void);
        
        //opperators
        ScavTrap   &operator=(const ScavTrap &rhs);

        //accessors
        void set_guardGate(const bool state);
        bool get_guardGate(void) const;

        //action
        void guardGate(void);
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &in);

#endif