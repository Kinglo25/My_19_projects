/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:31:15 by jandre            #+#    #+#             */
/*   Updated: 2021/07/29 17:16:34 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lamephonebook.hpp"

int main()
{
    lame_phone_book lpb;
    std::string     command;

    while (1)
    {
        std::cout << "What do you want to do? ";
        getline(std::cin, command);
        if (command == "ADD")
            lpb.add_contact();
        else if (command == "TEST")
            lpb.get_contact(0);
        else if (command == "SEARCH")
            lpb.search_contact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Please do something that i know, \
i am pretty dumb! Oh and without spaces please!" << std::endl << "REMINDER : ADD, SEARCH, EXIT" << std::endl;
	std::cout << std::endl;
    }
    std::cout << std::endl;
    return (0);
}