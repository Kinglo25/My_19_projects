/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:56:48 by jandre            #+#    #+#             */
/*   Updated: 2022/01/20 15:20:30 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "type one argument please" << std::endl;
        return (0);
    }
    Convert c((std::string)argv[1]);
    if (c.is_okay())
    {
        std::cout << "enter a value thats either a char, an int, a float or a double" << std::endl;
        return (0);
    }
    c.tochar();
    c.toint();
    c.tofloat();
    c.todouble();
    return (0);
}