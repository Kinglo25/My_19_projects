/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:07:01 by jandre            #+#    #+#             */
/*   Updated: 2022/02/01 11:42:55 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template <typename T>
void swap (T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
    return ;
}

template <typename T>
T min(T const &a, T const &b)
{
    return (a >= b) ? b : a;
}

template <typename T>
T max(T const &a, T const &b)
{
    return (a <= b) ? b : a;
}

#endif