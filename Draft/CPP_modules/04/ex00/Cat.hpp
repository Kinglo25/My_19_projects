/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:25 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 16:28:13 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat& cpy);
	~Cat();

	Cat& operator=(const Cat& rhs);

	void		makeSound() const;
private:
	Brain*	_brain;
};

#endif