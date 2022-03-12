/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:36:30 by jandre            #+#    #+#             */
/*   Updated: 2022/01/21 17:57:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *array, int n, void f(T const &array))
{
    int i;

    i = 0;
    while (i < n)
    {
        f(array[i]);
        i++;
    }
    return ;
}

template <typename T>
void send_back(T const &a)
{
    std::cout << a << std::endl;
    return ;
}

#endif