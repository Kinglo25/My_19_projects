/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:49:28 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/05 15:53:46 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>
#include <cmath>     

class Span
{
public:
struct SpanFullException : public std::exception
{
	const char* what() const throw()
	{
		return ("The Span is full");
	}
};
struct SpanInvalidException : public std::exception
{
	const char* what() const throw()
	{
		return ("The Span is invalid");
	}
};

// ----------------------------- Constructors ------------------------------ //
	Span();	// Default Constructor
	Span(unsigned int N);	// Fields Constructor
	Span(const Span& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~Span();	// Destructor

// ------------------------------- Operators ------------------------------- //
	Span & operator=(const Span& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	unsigned int get_size() const;
	void set_size(unsigned int input);
	

// --------------------------------- Methods ------------------------------- //

	void	addNumber(int n);
	void	addRandomNumber(unsigned int qty);
	int		shortestSpan();
	int		longestSpan();
	void	check_valid_span();

private:
	unsigned int size;
	std::vector<int> vector;

};

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _SPAN_ARGS _ARG(size)
#  define _SPAN_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _SPAN_ARGS  \
			  << "}" << std::endl;
# else

#  define _SPAN_AUTO(x, y) ;
#  define _SPAN_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* SPAN_HPP */
