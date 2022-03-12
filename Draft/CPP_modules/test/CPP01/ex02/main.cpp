/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:23:20 by jandre            #+#    #+#             */
/*   Updated: 2021/08/12 20:04:59 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Voila les adresse ou sont stockée la string:" << std::endl << std::endl;
    std::cout << "Adresse du pointeur:                  " << &str << std::endl;
    std::cout << "Adresse du pointeur via le pointeur:  " << stringPTR << std::endl;
    std::cout << "Adresse du pointeur via la référence: " << &stringREF << std::endl;
    std::cout << std::endl << "Maintenant les valeurs:" << std::endl << std::endl;
    std::cout << "Valeur via le pointeur:  " << *stringPTR << std::endl;
    std::cout << "Valeur via la référence: " << stringREF << std::endl;
    return (0);
}