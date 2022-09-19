/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:49:31 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/05 16:51:01 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// ----------------------------- Constructors ------------------------------ //
Span::Span() : size(0)
{
	_SPAN_AUTO(32, "Default Constructor");
}

Span::Span(const Span& c) : size(c.size)
{
	_SPAN_AUTO(32, "Copy Constructor");
	*this = c;
}

Span::Span(unsigned int N) : size(N)
{
	_SPAN_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Span::~Span()
{
	_SPAN_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Span & Span::operator=(const Span& c)
{
	_SPAN_AUTO(32, "Copy Assignement Operator");
	vector = c.vector;
	size = c.size;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //


// --------------------------------- Methods ------------------------------- //

void	Span::addNumber(int n)
{
	if (vector.size() >= size)
		throw SpanFullException();
	std::cout << n << std::endl;
	vector.push_back(n);
}

void	Span::addRandomNumber(unsigned int qty)
{
	srand (time(NULL));
	while (qty--)
	{
		try
		{
			addNumber(rand() % 100);			
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	Span::check_valid_span()
{
	if (vector.size() <= 1)
		throw SpanInvalidException();
}

int		Span::shortestSpan()
{
	check_valid_span();
	std::vector<int> tmp(vector);
	
	unsigned int ret = UINT_MAX;
	for (std::vector<int>::iterator it_1 = tmp.begin(); it_1 != tmp.end(); ++it_1)
	{
		for (std::vector<int>::iterator it_2 = it_1 + 1; it_2 != tmp.end(); ++it_2)
		{
			if (static_cast<unsigned int>(std::abs(*it_1 - *it_2)) < ret)
				ret = std::abs(*it_1 - *it_2);
		}
	}
	return (ret);
}

int		Span::longestSpan()
{
	check_valid_span();
	std::vector<int> tmp(vector);
	
	std::sort(tmp.begin(), tmp.end());
	return (std::abs(*tmp.begin() - tmp.end()[-1]));
}
