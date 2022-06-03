/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:33:16 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/31 21:31:39 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Conversion.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "One argument please" << std::endl;
        return (0);
    }
    Conversion c((std::string)argv[1]);
    if (c.is_okay())
    {
        std::cout << "Enter a char, an int, a float or a double" << std::endl;
        return (0);
    }
    c.tochar();
    c.toint();
    c.tofloat();
    c.todouble();
    return (0);
}