/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:27:20 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 12:34:51 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <string>
# include <exception>
# include <time.h>
# include <stdlib.h>

class Span {
    public:
        //Constructor et Destructor
        Span();
        Span(unsigned int N);
        Span(Span const &src);
        ~Span();
        
        //operator overloads
        Span &operator=(Span const &src);

        //Accessors

        //Actions
        void addNumber(int n);
        void addRange(int min, int max);
        int shortestSpan();
        int longestSpan();
        void printArray();
        void clearArray();
    
    private:
        std::vector<int>    _array;
        unsigned int        _n;
};

#endif