/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:17 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:35:09 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal {
    public:
        //Constructors & Destructors
        Cat(void);
        Cat(const Cat &src);
        ~Cat(void);
        
        //opperators
        Cat   &operator=(const Cat &rhs);

        //Action
        void makeSound(void) const;
};

#endif