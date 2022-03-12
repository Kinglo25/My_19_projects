/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:31:52 by jandre            #+#    #+#             */
/*   Updated: 2021/12/16 17:27:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//Constructor & Destructor
Ice::Ice(void)
{
	this->type = "ice";
	std::cout << "Materia Ice created" << std::endl;
    return ;
}

Ice::Ice(Ice const &copy)
{
	*this = copy;
    return ;
}

Ice::~Ice()
{
	std::cout << "Materia Ice destructed" << std::endl;
    return ;
}

//Actions
void	Ice::use(ICharacter &target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
    return ;
}

AMateria *Ice::clone(void) const
{
	std::cout << "Materia Ice cloned" << std::endl;
	return (new Ice(*this));
}

//operators
Ice&	Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
        this->type = rhs.getType();
	return (*this);
}