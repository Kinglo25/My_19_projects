/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:59:37 by jandre            #+#    #+#             */
/*   Updated: 2021/08/18 14:55:41 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void    complaining(int i)
{
    Karen karen;
    
    switch (i)
    {
        case 0:  
            std::cout << "[ DEBUG ]" << std::endl;
            karen.complain("DEBUG");
        case 1:  
            std::cout << "[ INFO ]" << std::endl;
            karen.complain("INFO");
        case 2:  
            std::cout << "[ WARNING ]" << std::endl;
            karen.complain("WARNING");
        case 3: 
            std::cout << "[ ERROR ]" << std::endl;
            karen.complain("ERROR");
            break ;
        default:
            std::cout << "Put a valid complain :" << std::endl << "DEBUG, INFO, WARNING, ERROR" << std::endl;
    }
    return ;
}

int main(int argc, char **argv)
{
    int i;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    std::string level;

    if (argc != 2)
    {
        std::cout << "Put a valid complain :" << std::endl << "DEBUG, INFO, WARNING, ERROR" << std::endl;
        return (0);
    }
    level = argv[1];
    i = 0;
    while (i < 4)
    {
        if (level.compare(levels[i]) == 0)
            break ;
        i++;
    }
    complaining(i);
    return (0);
}