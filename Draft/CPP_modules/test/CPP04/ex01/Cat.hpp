/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:17 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:34:53 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        //Constructors & Destructors
        Cat(void);
        Cat(const Cat &src);
        ~Cat(void);
        
        //opperators
        Cat   &operator=(const Cat &rhs);

        //Accessors
        std::string get_idea(int i) const;

        //Action
        void makeSound(void) const;
};

#endif