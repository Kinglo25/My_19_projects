/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:39:59 by jandre            #+#    #+#             */
/*   Updated: 2022/02/01 11:44:32 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int array_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string array_str[10] = {"ouai", "bienvenue", "dans", "le", "cpp", "07", "puis", "jsp", "quoi", "dire"};
    float array_float[10] = {0.23, 1.2344, 2.11, 3.000, 4.1233, 5.333, 6.434, 7.234, 8.234, 9.234};

    iter(array_int, 10, send_back);
    std::cout << std::endl;
    iter(array_str, 10, send_back);
    std::cout << std::endl;
    iter(array_float, 10, send_back);
    std::cout << std::endl;
    iter<int>(array_int, 10, send_back);
    std::cout << std::endl;
    iter<std::string>(array_str, 10, send_back);
    std::cout << std::endl;
    iter<float>(array_float, 10, send_back);
    return (0);
}