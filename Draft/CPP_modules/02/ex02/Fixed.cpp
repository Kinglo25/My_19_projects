/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:55:22 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/19 18:56:56 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
		: _FixedPoint(0)
{
}

Fixed::Fixed(const int value)
{
	this->_FixedPoint = (value << nb_fract_bits);
}

Fixed::Fixed(const float value)
{
	this->_FixedPoint = int(roundf(value * (1 << nb_fract_bits)));
}

Fixed::Fixed(const Fixed& cpy)
{
	this->_FixedPoint = cpy.getRawBits();
}

Fixed::~Fixed(void)
{
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	this->_FixedPoint = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed& rhs)
{
	return (this->_FixedPoint < rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed& rhs)
{
	return (this->_FixedPoint > rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs)
{
	return (this->_FixedPoint <= rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs)
{
	return (this->_FixedPoint >= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs)
{
	return (this->_FixedPoint == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs)
{
	return (this->_FixedPoint != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs)
{
	Fixed ans;
	
	ans.setRawBits(this->_FixedPoint + rhs.getRawBits());
	return (ans);
}

Fixed	Fixed::operator-(const Fixed& rhs)
{
	Fixed ans;
	
	ans.setRawBits(this->_FixedPoint - rhs.getRawBits());
	return (ans);
}

Fixed	Fixed::operator*(const Fixed& rhs)
{
	Fixed ans;
	
	ans.setRawBits(this->_FixedPoint * rhs.getRawBits() >> nb_fract_bits);
	return (ans);
}

Fixed	Fixed::operator/(const Fixed& rhs)
{
	Fixed ans;
	
	ans.setRawBits(this->_FixedPoint * (1 << nb_fract_bits) / rhs.getRawBits());
	return (ans);
}

Fixed& Fixed::operator++()
{
	this->_FixedPoint++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_FixedPoint--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._FixedPoint > b._FixedPoint)
		return b;
	return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._FixedPoint < b._FixedPoint)
		return b;
	return a;
}

int		Fixed::getRawBits(void) const
{
	return (this->_FixedPoint);
}

void	Fixed::setRawBits(int const value)
{
	this->_FixedPoint = value;
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
