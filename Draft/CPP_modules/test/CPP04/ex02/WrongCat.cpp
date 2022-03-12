/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat copy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:28 by jandre            #+#    #+#             */
/*   Updated: 2021/11/26 10:35:22 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//Constructor Destructor

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat &src)
{
    *this = src;
    std::cout << "WrongCat copied" << std::endl;
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructed" << std::endl;
    return ;
}

//operator

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
        this->set_type(rhs.get_type());
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const WrongCat &in)
{
    out << in.get_type();
    return (out);
}

//Actions

void WrongCat::makeSound(void) const
{
    std::cout << "Miaouw Miaouw Miaouw" << std::endl;
    return ;
}