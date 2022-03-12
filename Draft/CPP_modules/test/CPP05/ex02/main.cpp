/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:53:24 by jandre            #+#    #+#             */
/*   Updated: 2022/01/31 15:25:02 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
    PresidentialForm pres("coco");
    PresidentialForm pres2("coco", "form P");
    PresidentialForm pres3(pres2);
    ShrubberyForm schru("mara");
    ShrubberyForm schru2("popo", "form S");
    ShrubberyForm schru3(schru2);
    RobotomyForm rob("bebe");
    RobotomyForm rob2("bebe", "form R");
    RobotomyForm rob3(rob2);


    sendText("\n");

    //test all overloads
    sendText("Testing all the overloads on all the bureacrat and form created");
    std::cout << pres << std::endl;
    std::cout << pres2 << std::endl;
    std::cout << pres3 << std::endl;
    std::cout << schru << std::endl;
    std::cout << schru2 << std::endl;
    std::cout << schru3 << std::endl;
    std::cout << rob << std::endl;
    std::cout << rob2 << std::endl;
    std::cout << rob3 << std::endl << std::endl;
    std::cout << joel << std::endl;
    std::cout << marcel << std::endl;
    std::cout << basic << std::endl;
    sendText("\n");

    //test exeptions
    sendText("Testing execute without the form being signed");
    marcel.executeForm(schru);
    marcel.executeForm(pres);
    marcel.executeForm(rob);
    sendText("\n");
    sendText("Testing the signature of the form with good and wrong grade");
    joel.signForm(schru);
    marcel.signForm(schru);
    marcel.signForm(pres);
    marcel.signForm(schru);
    marcel.signForm(rob);
    sendText("\n");
    sendText("Testing to execute with wrong and good grade");
    joel.executeForm(schru);
    marcel.executeForm(schru);
    marcel.executeForm(rob);
    marcel.executeForm(rob);
    marcel.executeForm(rob);
    marcel.executeForm(rob);
    marcel.executeForm(rob);
    marcel.executeForm(rob);
    marcel.executeForm(pres);    
    sendText("\n");
    return (0);
}