/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:52:48 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 20:35:31 by lmajerus         ###   ########.fr       */
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

	Zombie();
	~Zombie();

	void	announce(void) const;
	void	set_name(std::string name);

};

Zombie* zombie_horde( int N, std::string name );

#endif