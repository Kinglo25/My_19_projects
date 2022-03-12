/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:28:30 by jandre            #+#    #+#             */
/*   Updated: 2022/02/01 15:59:52 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"
#include <iostream>

int main()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    b = a;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    double a1 = 29889.32;
    double b1 = 3.123;
    ::swap( a, b );
    std::cout << "a = " << a1 << ", b = " << b1 << std::endl;
    std::cout << "min( a, b ) = " << ::min( a1, b1 ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a1, b1 ) << std::endl;
    float a2 = 2123123;
    float b2 = 3.22222;
    ::swap( a, b );
    std::cout << "a = " << a2 << ", b = " << b2 << std::endl;
    std::cout << "min( a, b ) = " << ::min( a2, b2 ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a2, b2 ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}