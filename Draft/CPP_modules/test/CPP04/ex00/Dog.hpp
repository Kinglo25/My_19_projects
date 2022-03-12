/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:48:52 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:35:12 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal {
    public:
        //Constructors & Destructors
        Dog(void);
        Dog(const Dog &src);
        ~Dog(void);
        
        //opperators
        Dog   &operator=(const Dog &rhs);

        //actions
        void makeSound(void) const;
};

#endif