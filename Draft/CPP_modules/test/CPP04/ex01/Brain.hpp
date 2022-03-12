/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:06:49 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:34:56 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <cstdlib>

class Brain {
    private:
        std::string idea[100];

    public:
        //Constructors & Destructors
        Brain(void);
        Brain(const Brain &src);
        ~Brain();
        
        //opperators
        Brain   &operator=(const Brain &rhs);

        //accessor
        std::string get_idea(int i) const;
        void        set_idea(std::string const new_idea, int i);
        
        //actions
};

#endif