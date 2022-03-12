/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:14:31 by jandre            #+#    #+#             */
/*   Updated: 2022/02/02 15:02:29 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SIZE 10

int main()
{
    Span def;
    Span span(SIZE);
    Span span_huge(100000);
    Span span_cpy(span);
    Span span_empty(10);

    std::cout << "span : ";
    span.printArray();
    std::cout << "span_huge : ";
    span_huge.printArray();
    std::cout << "span_empty : ";
    span_cpy.printArray();
    srand(time(NULL));
    std::cout << "Adding mumbers to a span :" << std::endl;
    try
    {
        for (int i = 0; i < SIZE; i++)
            span.addNumber(rand() % 100);
    }
    catch (std::exception &e)
    {
        std::cout << "added too much numbers" << std::endl;
    }
    std::cout << std::endl << "Trying to add too much number to a span :" << std::endl;
    try
    {
        for (int i = 0; i < SIZE; i++)
            span.addNumber(i);
    }
    catch (std::exception &e)
    {
        std::cout << "added too much numbers" << std::endl;
    }
    std::cout << "Filling a huge span to see if it works :" << std::endl;
    try
    {
        for (int i = 0; i < 100000; i++)
            span_huge.addNumber(rand() % 1000);
    }
    catch (std::exception &e)
    {
        std::cout << "added too much numbers" << std::endl;
    }
    std::cout << std::endl << "Trying to calculate span of an array of max size 0 :" << std::endl;
    try
    {
        int l = def.longestSpan();
        int s = def.shortestSpan();
        std::cout << "longest span : " << l << std::endl;
        std::cout << "shortest span : " << s << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "there is not enough number to calculate a span" << std::endl;
    }
    std::cout << std::endl << "Trying to calculate span of an array of a size x but empty : " << std::endl;
    try
    {
        int l = span_empty.longestSpan();
        int s = span_empty.shortestSpan();
        std::cout << "longest span : " << l << std::endl;
        std::cout << "shortest span : " << s << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "there is not enough number to calculate a span" << std::endl;
    }
    std::cout << std::endl << "printing the base span and the span constructed by copy : " << std::endl;
    std::cout << "span : ";
    span.printArray();
    span_cpy = span;
    std::cout << "span_cpy : ";
    span_cpy.printArray();
    std::cout <<std::endl << "finding the longest span and shortest span of those span : " << std::endl;
    try
    {
        int l = span.longestSpan();
        int s = span.shortestSpan();
        std::cout << "longest span : " << l << std::endl;
        std::cout << "shortest span : " << s << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "there is not enough number to calculate a span" << std::endl;
    }
   // span_huge.printArray();
    std::cout << std::endl << "trying the same with a huge span : " << std::endl;
    try
    {
        int l = span_huge.longestSpan();
        int s = span_huge.shortestSpan();
        std::cout << "longest span : " << l << std::endl;
        std::cout << "shortest span : " << s << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "there is not enough number to calculate a span" << std::endl;
    }
    std::cout << std::endl << "clearing the span, printing it to prove it is empty and then adding too much numbers via the spanaddrange fonction :" << std::endl;
    span.clearArray();
    std::cout << "span : ";
    span.printArray();
    try
    {
        span.addRange(0, 10000);
    }
    catch (std::exception &e)
    {
        std::cout << "added too much numbers" << std::endl;
    }
    std::cout << std::endl << "Adding a good number of numbers via the add range fonction then printing the span :" << std::endl;
    Span span2(10);
    try
    {
        span2.addRange(4, 9);
    }
    catch (std::exception &e)
    {
        std::cout << "added too much numbers" << std::endl;
    }
    std::cout << "span2 : ";
    span2.printArray();
    std::cout << "span : ";
    span.printArray();
    return (0);
}