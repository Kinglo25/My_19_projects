/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:53:24 by jandre            #+#    #+#             */
/*   Updated: 2022/01/31 15:14:48 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void sendText(std::string const txt)
{
    std::cout << txt << std::endl;
    return ;
}

int main()
{
    //Test all constructors
    sendText("Testing all the constructors");
    Bureaucrat joel("Joel", 150);
    Bureaucrat marcel("Marcel", 1);
    Bureaucrat basic;
    Bureaucrat joel_copy(joel);
    sendText("\n");

    //test all overloads
    sendText("Testing all the overloads on all the bureaucrat created");
    std::cout << joel << std::endl;
    std::cout << marcel << std::endl;
    std::cout << basic << std::endl;
    std::cout << joel_copy << std::endl;
    joel_copy = marcel;
    std::cout <<  "After egaling joel to marcel : " << joel_copy << std::endl;
    sendText("\n");

    //test exeptions
    sendText("Testing increase and decrease and seeing if exeptions works");
    joel.decGrade();
    std::cout << joel << std::endl;
    joel.incGrade();
    std::cout << joel << std::endl;
    marcel.incGrade();
    std::cout << marcel << std::endl;
    marcel.decGrade();
    std::cout << marcel << std::endl;
    sendText("\n");

    //test constructor with wrong grades
    sendText("Testing exeption on the creation of a bureaucrat");
    Bureaucrat Kokori("Kokori", 1444);
    Bureaucrat Kakari("Kakari", -1444);
    std::cout << Kokori << std::endl;
    std::cout << Kakari << std::endl;
    return (0);
}