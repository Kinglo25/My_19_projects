/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:55:25 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/19 18:40:21 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath> 

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& cpy);
	~Fixed();

	Fixed&	operator=(const Fixed& rhs);

	bool	operator<(const Fixed& rhs);
	bool	operator>(const Fixed& rhs);
	bool	operator<=(const Fixed& rhs);
	bool	operator>=(const Fixed& rhs);
	bool	operator==(const Fixed& rhs);
	bool	operator!=(const Fixed& rhs);

	Fixed	operator+(const Fixed& rhs);
	Fixed	operator-(const Fixed& rhs);
	Fixed	operator*(const Fixed& rhs);
	Fixed	operator/(const Fixed& rhs);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);	

	static			Fixed& min(Fixed& a, Fixed& b);
	static const	Fixed& min(const Fixed& a, const Fixed& b);
	static			Fixed& max(Fixed& a, Fixed& b);
	static const	Fixed& max(const Fixed& a, const Fixed& b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat( void ) const;
	int		toInt( void ) const;	

private:
	static int const nb_fract_bits = 8;
	int _FixedPoint;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif