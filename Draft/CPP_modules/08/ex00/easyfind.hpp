/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:12:50 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/05 14:30:57 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <iostream>

struct NotInContainerException : public std::exception
{
	const char* what() const throw()
	{
		return ("Number not in the container");
	}
};

template <class T>
typename T::iterator easyfind(T& container, int x)
{
	for (typename T::iterator it = container.begin();
		it != container.end(); ++it)
	{
		if (*it == x)
			return (it);
	}
	throw NotInContainerException();
}

#endif