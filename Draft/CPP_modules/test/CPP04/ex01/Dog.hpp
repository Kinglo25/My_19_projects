/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:48:52 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:34:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private: 
        Brain *brain;
    public:
        //Constructors & Destructors
        Dog(void);
        Dog(const Dog &src);
        ~Dog(void);
        
        //opperators
        Dog   &operator=(const Dog &rhs);

        //Accessors
        std::string get_idea(int i) const;

        //actions
        void makeSound(void) const;
};

#endif