/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:15:00 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:34:40 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//Constructor destructor

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "WrongAnimal created" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "WrongAnimal copied" << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructed" << std::endl;
    return ;
}

//Accessors

std::string WrongAnimal::get_type(void) const
{
    return (this->type);
}

void WrongAnimal::set_type(std::string const new_type)
{
    this->type = new_type;
    return ;
}

//operator

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
        this->set_type(rhs.get_type());
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const WrongAnimal &in)
{
    out << in.get_type();
    return (out);
}

//Actions

void WrongAnimal::makeSound(void) const
{
    std::cout << "Noise from an animal??? BLBLBLBL" << std::endl;
    return ;
}