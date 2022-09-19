/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:01:47 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/03 14:48:30 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tempolado.hpp"
#include <iostream>

int	main()
{

	{
	float	a = 21.445f;
	float	b = 42.445f;

	std::cout << "The max of a: " << a << " and b: " << b << " is:" <<
	"\t" << max(a, b) << std::endl;

	std::cout << "The min of a: " << a << " and b: " << b << " is:" <<
	"\t" << min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "before:\n\ta: " << a << "\n\tb: " << b << std::endl;
	swap(a, b);
	std::cout << "after:\n\ta: " << a << "\n\tb: " << b << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------------------------" << std::endl << std::endl;

	{
	std::string	a = "String A";
	std::string b = "String B";

	std::cout << "The max of a: " << a << " and b: " << b << " is:" <<
	"\t" << ::max(a, b) << std::endl;

	std::cout << "The min of a: " << a << " and b: " << b << " is:" <<
	"\t" << ::min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "before:\n\ta: " << a << "\n\tb: " << b << std::endl;
	::swap(a, b);
	std::cout << "after:\n\ta: " << a << "\n\tb: " << b << std::endl;
	}

	return (0);
}