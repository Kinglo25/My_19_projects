/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:45:27 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/14 20:10:27 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    return ;
}

Harl::~Harl()
{
    return ;
}

void    Harl::debug(void)
{
    std::cout   << "I love having extra bacon for my "
                << "7XL-double-cheese-triple-pickle-specialketchup "
                << "burger. I really do!"
                << std::endl;
}

void	Harl::info( void )
{
    std::cout   << "I cannot believe adding extra bacon costs more "
                << "money. You didn’t put enough bacon in my burger! "
                << "If you did, I wouldn’t be asking for more!"
                << std::endl;
}
void	Harl::warning( void )
{
    std::cout   << "I think I deserve to have some extra "
                << "bacon for free. I’ve been coming for years"
                << "whereas you started working here since last month."
                << std::endl;
}
void	Harl::error( void )
{
    std::cout   << "This is unacceptable! I want to "
                << "speak to the manager now."
                << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[NB_LVL] = 
    {   
        "DEBUG", 
        "INFO",
        "WARNING",
        "ERROR"
    };
    void (Harl::*ptf[NB_LVL])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < NB_LVL; i++)
    {
        if (levels[i] == level)
            (this->*ptf[i])();
    }
}
