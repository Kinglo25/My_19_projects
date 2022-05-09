/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:49:54 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/06 16:50:00 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

# define NB_LVL 4
# define DEBUG 1
# define INFO 2
# define WARNING 3
# define ERROR 4

class Harl
{
private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:

	Harl();
	~Harl();

	void	complain(std::string level);
};

#endif
