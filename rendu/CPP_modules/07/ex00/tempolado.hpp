/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempolado.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:01:53 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/03 14:47:35 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPOLADO_HPP
# define TEMPOLADO_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T const &a, T const &b)
{
	return (a < b) ? a : b;
}

template <typename T>
T	max(T const &a, T const &b)
{
	return (a > b) ? a : b;
}

#endif