/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:43:40 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/15 13:57:37 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& cpy);
	~Fixed();

	Fixed& operator=(const Fixed& rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	static int const nb_bits = 8;
	int _rawBits;
};
#endif