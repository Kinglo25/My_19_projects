/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:26:48 by jandre            #+#    #+#             */
/*   Updated: 2021/11/19 15:30:42 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP
# define CLAPTRAP
# include <string>
# include <iostream>

class ClapTrap {
    protected:
		std::string name;
        int         hitpoints;
        int         energy;
        int         attackdmg;
    
    public:
        //Constructors & Destructors
        ClapTrap(void);
        ClapTrap(const ClapTrap &src);
        ClapTrap(std::string name);
        ~ClapTrap(void);
        
        //opperators
        ClapTrap   &operator=(const ClapTrap &rhs);

        //accessors
        int get_attackdmg(void) const;
        std::string get_name(void) const;
        int get_hitpoints(void) const;
        int get_energy(void) const;
        void set_attackdmg(int const new_value);
        void set_energy(int const new_value);
        void set_hitpoints( int const new_value);
        void set_name(std::string const new_name);
        
        //actions
        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &in);

#endif