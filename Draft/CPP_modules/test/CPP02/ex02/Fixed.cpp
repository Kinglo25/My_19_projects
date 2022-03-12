/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:42 by jandre            #+#    #+#             */
/*   Updated: 2021/11/18 16:20:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor Destructor

Fixed::Fixed(void) : value(0)
{
    return ;
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
    return ;
}

Fixed::Fixed(const int i)
{
	this->setRawBits(i << this->fractional_bits);
    return ;
}

Fixed::Fixed(const float f)
{
	this->setRawBits((int)(roundf(f * (1 << this->fractional_bits))));
    return ;
}

Fixed::~Fixed(void)
{
    return ;
}

//Comparators

bool	Fixed::operator>(const Fixed &rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

//Operators
Fixed   &Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &in)
{
    out << in.toFloat();
    return (out);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

//Increments
//pre-increments
Fixed	&Fixed::operator++(void)
{
    this->value += 1;
    return (*this);
}

Fixed	&Fixed::operator--(void)
{
    this->value -= 1;
    return (*this);
}

//post-increments
Fixed	Fixed::operator++(int)
{
    Fixed tmp;

	tmp = (*this);
    this->operator++();
    return (tmp);
}

Fixed	Fixed::operator--(int)
{
    Fixed tmp;

	tmp = (*this);
    this->operator--();
    return (tmp);
}

//Accessors
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

//max & min
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
