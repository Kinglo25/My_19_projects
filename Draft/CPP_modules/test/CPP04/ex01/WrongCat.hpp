/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:17 by jandre            #+#    #+#             */
/*   Updated: 2021/11/26 10:30:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        //Constructors & Destructors
        WrongCat(void);
        WrongCat(const WrongCat &src);
        ~WrongCat(void);
        
        //opperators
        WrongCat   &operator=(const WrongCat &rhs);

        //Actions
        void makeSound(void) const;
};

#endif