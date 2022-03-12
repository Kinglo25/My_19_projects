/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:53:07 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 20:39:49 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
int &easyfind(T& data, int toFind)
{
    typename T::iterator it;
    it = std::find(data.begin(), data.end(), toFind);
    if (it != data.end())
        return (*it);
    throw std::exception();
}

#endif