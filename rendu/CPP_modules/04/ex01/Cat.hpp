/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:25 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 16:58:51 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat& cpy);
	~Cat();

	Cat& operator=(const Cat& rhs);

	virtual void		makeSound() const;
	void				set_idea(size_t i, std::string idea);
	const std::string	get_idea(size_t i);
private:
	Brain*	_brain;
};

#endif