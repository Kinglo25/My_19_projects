/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:46 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/03 15:09:52 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <stdio.h>

template <typename T>
void	iter(T* tab, size_t size, void (*f)(const T&))
{
	for (size_t i = 0; i < size; i++)
		f(tab[i]);
}

#endif