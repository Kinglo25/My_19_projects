/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:29 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 16:57:37 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog& cpy);
	~Dog();

	Dog& operator=(const Dog& rhs);

	virtual void		makeSound() const;
	void				set_idea(size_t i, std::string idea);
	const std::string	get_idea(size_t i);
private:
	Brain*	_brain;
};

#endif