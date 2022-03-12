/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:59:41 by jandre            #+#    #+#             */
/*   Updated: 2021/08/18 14:51:30 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
    return ;
}

Karen::~Karen(void)
{
    return ;
}

void    Karen::debug(void)
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
    return ;
}

void    Karen::info(void)
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    return ;
}

void    Karen::warning(void)
{
    std::cout << " think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
    return ;
}

void    Karen::error(void)
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
    return ;
}

void    Karen::complain(std::string level)
{
    int i;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Karen::*(fct[4]))(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
    i = 0;
    while (i < 4)
    {
        if (level.compare(levels[i]) == 0)
            (this->*(fct[i]))();
        i++;
    }
    return ;
}