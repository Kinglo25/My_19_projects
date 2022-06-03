/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:46:34 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 15:57:24 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& cpy);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& rhs);

	std::string	get_type() const;
	void		set_type(std::string const type);

	virtual void	makeSound() const;


protected:
	std::string	type_;
};

#endif