/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:31:52 by jandre            #+#    #+#             */
/*   Updated: 2021/12/15 16:41:22 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//Constructor & Destructor
Cure::Cure(void)
{
	this->type = "cure";
	std::cout << "Materia Cure created" << std::endl;
    return ;
}

Cure::Cure(Cure const &copy)
{
	*this = copy;
    return ;
}

Cure::~Cure()
{
	std::cout << "Materia Cure destructed" << std::endl;
    return ;
}

//Actions
void	Cure::use(ICharacter &target)
{
	std::cout << " heals " << target.getName() << "\'s wound" << std::endl;
    return ;
}

AMateria *Cure::clone(void) const
{
	std::cout << "Materia Cure cloned" << std::endl;
	return (new Cure(*this));
}


//operators
Cure&	Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
        this->type = rhs.getType();
	return (*this);
}