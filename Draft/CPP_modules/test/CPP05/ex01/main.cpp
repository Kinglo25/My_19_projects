/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:53:24 by jandre            #+#    #+#             */
/*   Updated: 2022/01/31 15:18:20 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void sendText(std::string const txt)
{
    std::cout << txt << std::endl;
    return ;
}

int main()
{
    //Test all constructors
    sendText("Testing all the constructors for Bureaucrats");
    Bureaucrat joel("Joel", 150);
    Bureaucrat marcel("Marcel", 1);
    Bureaucrat basic;
    Bureaucrat joel_copy(joel);
    sendText("\n");

    //Test constructors Form
    sendText("Testing all the constructors for Forms");
    Form A;
    Form B("Form B", 150, 150);
    Form B_cpy(B);
    Form C("Form C", 1, 1);
    Form C_cpy(C);
    sendText("\n");

    //test all overloads
    sendText("Testing all the overloads on all the bureacrat and form created");
    std::cout << joel << std::endl;
    std::cout << marcel << std::endl;
    std::cout << basic << std::endl;
    std::cout << joel_copy << std::endl;
    joel_copy = marcel;
    std::cout << "After egaling joel to marcel : " << joel_copy << std::endl;
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << B_cpy << std::endl;
    std::cout << C << std::endl;
    B_cpy = C;
    std::cout << "After egaling B_cpy to C : " << B_cpy << std::endl;
    sendText("\n");

    //test exeptions
    sendText("Testing increase and decrease and seeing if exceptions works");
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

    //test sign form with good and wrong grades
    sendText("test sign form with good and wrong grades and sign form already signed");
    C.beSigned(Kokori);
    C.beSigned(Kakari);
    C.beSigned(marcel);
    C.beSigned(Kokori);
    B.beSigned(joel);
    B_cpy = C;
    std::cout << "After egaling B_cpy to C : " << B_cpy << std::endl;
    Kokori.signForm(C_cpy);
    Kakari.signForm(C_cpy);
    marcel.signForm(C_cpy);
    Kokori.signForm(C_cpy);
    joel.signForm(B_cpy);

    return (0);
}