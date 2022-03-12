/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:42 by jandre            #+#    #+#             */
/*   Updated: 2021/11/18 15:39:48 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i << this->fractional_bits);
    return ;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)(roundf(f * (1 << this->fractional_bits))));
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed   &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return (*this);
}

int     Fixed::getRawBits(void) const
{
    return (this->value);
}

void    Fixed::setRawBits(int const raw)
{
    this->value = raw;
    return ;
}

float   Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (1 << this->fractional_bits));
}

int     Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &in)
{
    out << in.toFloat();
    return (out);
}