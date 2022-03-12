/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:04 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:43:21 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog created" << std::endl;
    return ;
}

Dog::Dog(const Dog &src)
{
    this->brain = new Brain;
    *this = src;
    std::cout << "Dog copied" << std::endl;
    return ;
}

Dog::~Dog(void)
{
    delete(this->brain);
    std::cout << "Dog destructed" << std::endl;
    return ;
}

//operator

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        if (this->brain)
            delete (this->brain);
        this->brain = new Brain(*(rhs.brain));
        this->set_type(rhs.get_type());
    }
    return (*this);
}

//Accessor

std::string Dog::get_idea(int i) const
{
    return (this->brain->get_idea(i));
}

//Actions

void Dog::makeSound(void) const
{
    std::cout << "Wouf Wouf Wouf" << std::endl;
    return ;
}