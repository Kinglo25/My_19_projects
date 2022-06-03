/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:47 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 16:00:54 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
public:
	Brain();
	Brain(const Brain& cpy);
	~Brain();

	Brain&	operator=(const Brain& rhs);

	const std::string	get_idea(size_t i) const;
	void				set_idea(size_t i, std::string idea);

private:
	std::string	_ideas[100];
};

#endif