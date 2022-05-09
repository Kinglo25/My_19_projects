/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:09:04 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 01:25:42 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
		: _FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_FixedPoint = (value << nb_fract_bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_FixedPoint = int(roundf(value * (1 << nb_fract_bits)));
}

Fixed::Fixed(const Fixed& cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_FixedPoint = cpy.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_FixedPoint = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_FixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_FixedPoint = raw;
}

float	Fixed::toFloat( void ) const
{
	return (float(this->_FixedPoint) / (1 << nb_fract_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->_FixedPoint >> nb_fract_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
