/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:44:29 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:34:59 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        //Constructors & Destructors
        Animal(void);
        Animal(const Animal &src);
        virtual ~Animal();
        
        //opperators
        Animal   &operator=(const Animal &rhs);

        //accessors
        std::string get_type(void) const;
        void set_type(std::string const new_type);
        
        //actions
        virtual void makeSound(void) const;
};

#endif