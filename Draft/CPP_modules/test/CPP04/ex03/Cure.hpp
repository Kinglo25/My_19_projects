/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:15:19 by jandre            #+#    #+#             */
/*   Updated: 2021/12/15 16:23:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE
# define CURE
# include "AbstractClasses.hpp"

class Cure : public AMateria {
    public:
        //Constructors & Destructors
        Cure(void);
        Cure(Cure const &copy);
        ~Cure(void);
        
        //opperators
        Cure &operator=(const Cure &rhs);

        //Action
        AMateria *clone(void) const;
        void use(ICharacter& target);
};

#endif