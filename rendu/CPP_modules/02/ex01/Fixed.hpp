/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:08:59 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/19 17:51:22 by lmajerus         ###   ########.fr       */
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

	Fixed& operator=(const Fixed& rhs);

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