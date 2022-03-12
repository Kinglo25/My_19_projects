/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:19:30 by jandre            #+#    #+#             */
/*   Updated: 2022/01/20 16:44:44 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

Base * generate(void)
{
    Base *p = NULL;

	srand (time(NULL));
	int	per = rand() % 3;
    if (per == 0)
        p = new A();
    else if (per == 1)
        p = new B();
    else if (per == 2)
        p = new C();
    return (p);
}

void identify(Base * p)
{
    std::cout << "ptr : " <<std::endl;
    if (A *a = dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base & p)
{
    std::cout << "ref : " <<std::endl;
    try 
    {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << 'A' << std::endl;
    }
	catch (std::exception &e) 
    {
        static_cast<void>(e);
    }
	try 
    {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << 'B' << std::endl;
    }
	catch (std::exception &e) 
    {
        static_cast<void>(e);
    }
    try 
    {
        static_cast<void>(dynamic_cast<C&>(p));
        std::cout << 'C' << std::endl;
    }
	catch (std::exception &e) 
    {
        static_cast<void>(e);
    }
}
int main ()
{
    Base *base_ptr = generate();

    identify(base_ptr);
    identify(*base_ptr);
    delete base_ptr;
    return (0);
}
