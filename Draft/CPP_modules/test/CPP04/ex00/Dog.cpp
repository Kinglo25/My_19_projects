/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:04 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:35:10 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog created" << std::endl;
    return ;
}

Dog::Dog(const Dog &src)
{
    *this = src;
    std::cout << "Dog copied" << std::endl;
    return ;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructed" << std::endl;
    return ;
}

//operator

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        this->set_type(rhs.get_type());
    return (*this);
}

//Actions

void Dog::makeSound(void) const
{
    std::cout << "Wouf Wouf Wouf" << std::endl;
    return ;
}