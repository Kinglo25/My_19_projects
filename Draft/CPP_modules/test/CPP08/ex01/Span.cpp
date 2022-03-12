/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:39:53 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 12:41:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructors & Destructors
Span::Span() : _n(0)
{
    return;
}

Span::Span(unsigned int N) : _n(N)
{
    return ;
}

Span::Span(Span const & src)
{
    *this = src;
    return ;
}

Span::~Span()
{
    return ;
}

//operator overloads
Span &Span::operator=(Span const &src)
{
    if (this != &src)
    {
        this->_n = src._n;
        this->_array = src._array;
    }
    return (*this);
}

//Action
void Span::addNumber(int n)
{
    if (this->_array.size() >= this->_n)
        throw (std::exception());
    this->_array.push_back(n);
    return ;
}

void Span::addRange(int min, int max)
{
    int tmp;

    if (min > max)
    {
        tmp = min;
        min = max;
        max = tmp;
    }
    for (; min <= max; min++)
        this->addNumber(min);
    return ;
}

int Span::shortestSpan()
{
    if (this->_n < 2 || this->_array.size() == 0 || this->_array.size() == 1)
        throw (std::exception());
    std::vector<int> tmp(this->_array);
    std::sort(tmp.begin(), tmp.end());
    int ans = abs(*(tmp.end() - 1) - *(tmp.begin()));
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        if (it + 1 != tmp.end())
            ans = std::min(ans, abs(*(it + 1) - *it));
    }
    return (ans);
}

int Span::longestSpan()
{
    if (this->_n < 2 || this->_array.size() == 0 || this->_array.size() == 1)
        throw (std::exception());
    std::vector<int> tmp(this->_array);
    std::sort(tmp.begin(), tmp.end());
    int ans = abs(*(tmp.end() - 1) - *(tmp.begin()));
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        if (it + 1 != tmp.end())
            ans = std::max(ans, abs(*(it + 1) - *it));
    }
    return (ans);
}

void Span::printArray()
{
    if (this->_array.size() <= 0)
    {
        std::cout << "Array empty" << std::endl;
        return ;
    }
    std::vector<int>::iterator it = this->_array.begin();
    std::cout << "( ";
    for (; it + 1 != this->_array.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << *it << " )" << std::endl;
    return ;
}

void Span::clearArray()
{
    this->_array.clear();
    return ;
}