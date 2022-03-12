/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:44:29 by jandre            #+#    #+#             */
/*   Updated: 2021/11/26 10:25:11 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        //Constructors & Destructors
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &src);
        ~WrongAnimal(void);
        
        //opperators
        WrongAnimal   &operator=(const WrongAnimal &rhs);

        //accessors
        std::string get_type(void) const;
        void set_type(std::string const new_type);
        
        //actions
        void makeSound(void) const;
};

#endif