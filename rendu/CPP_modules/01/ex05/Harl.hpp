/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:45:29 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/06 16:46:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

# define NB_LVL 4

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
