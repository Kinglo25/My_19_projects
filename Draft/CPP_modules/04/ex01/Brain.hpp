/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:47 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 16:27:37 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
public:
	Brain();
	Brain(std::string type);
	Brain(const Brain& cpy);
	~Brain();

	Brain& operator=(const Brain& rhs);

	std::string	ideas[100];
};

#endif