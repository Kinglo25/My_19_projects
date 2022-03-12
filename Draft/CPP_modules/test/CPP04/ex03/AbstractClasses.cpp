/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractClasses.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:06:52 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 17:10:21 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractClasses.hpp"


AMateria::AMateria(void)
{
	this->type = "NOTYPE";
    return ;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
    return ;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
    return ;
}

AMateria::~AMateria()
{
    return ;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

AMateria&	AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
        this->type = rhs.getType();
	return (*this);
}