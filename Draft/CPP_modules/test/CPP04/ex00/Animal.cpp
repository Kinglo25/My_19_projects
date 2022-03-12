/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:15:00 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:35:04 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Constructor destructor

Animal::Animal(void) : type("Animal")
{
    std::cout << "Animal created" << std::endl;
    return ;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "Animal copied" << std::endl;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructed" << std::endl;
    return ;
}

//Accessors

std::string Animal::get_type(void) const
{
    return (this->type);
}

void Animal::set_type(std::string const new_type)
{
    this->type = new_type;
    return ;
}

//operator

Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
        this->set_type(rhs.get_type());
    return (*this);
}

//Actions

void Animal::makeSound(void) const
{
    std::cout << "Noise from an animal??? BLBLBLBL" << std::endl;
    return ;
}