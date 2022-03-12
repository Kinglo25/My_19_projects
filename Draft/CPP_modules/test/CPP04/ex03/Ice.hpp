/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:15:19 by jandre            #+#    #+#             */
/*   Updated: 2021/12/16 17:16:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE
# define ICE
# include "AbstractClasses.hpp"

class Ice : public AMateria {
    public:
        //Constructors & Destructors
        Ice(void);
        Ice(Ice const &copy);
        ~Ice(void);
        
        //opperators
        Ice &operator=(const Ice &rhs);

        //Action
        AMateria *clone(void) const;
        void use(ICharacter& target);
};

#endif