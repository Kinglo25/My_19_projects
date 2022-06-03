/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:32 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 15:57:03 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& cpy);
	virtual ~Animal();

	Animal& operator=(const Animal& rhs);

	std::string	get_type() const;
	void		set_type(std::string const type);

	virtual void	makeSound() const;


protected:
	std::string	type_;
};

#endif