/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:52:48 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 19:43:14 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:

	std::string	_name;

public:

	Zombie(std::string name);
	~Zombie();

	void	announce(void) const;

};

Zombie* newZombie(std::string name);

void	randomChump(std::string name);

#endif