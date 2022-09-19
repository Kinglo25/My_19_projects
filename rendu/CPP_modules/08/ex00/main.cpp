/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:12:56 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/05 14:40:30 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int> test;
	std::list<int>::iterator it;
	for (int i = 1; i <= 19; i++)
		test.push_back(i);
	try
	{
		it = ::easyfind(test, 19);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it = ::easyfind(test, 42);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}