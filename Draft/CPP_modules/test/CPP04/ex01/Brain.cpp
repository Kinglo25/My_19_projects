/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:06:29 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:34:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string ideas[8] = { "EAT", "PLAY", "CUDDLE", "DRINK", "WTF", "FIGHT", "GRRR", "SHHH"};

//Constructor destructor

Brain::Brain(void)
{
    int i;

    i = -1;
    while (++i < 100)
        this->idea[i] = ideas[rand()%8];
    std::cout << "Brain created" << std::endl;
    return ;
}

Brain::Brain(const Brain &src)
{
    *this = src;
    std::cout << "Brain copied" << std::endl;
    return ;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructed" << std::endl;
    return ;
}

//operator

Brain &Brain::operator=(const Brain &rhs)
{
    int i;

    i = 0;
    if (this != &rhs)
    {
        while (i < 100)
        {
            this->set_idea(rhs.get_idea(i), i);
            i++;
        }
    }
    return (*this);
}

//accesssor

std::string Brain::get_idea(int i) const
{
    return (this->idea[i]);
}

void Brain::set_idea(std::string const new_idea, int i)
{
    this->idea[i] = new_idea;
    return ;
}

//Actions
