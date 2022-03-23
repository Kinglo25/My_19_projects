/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:05:48 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/22 21:21:21 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string* brain_ptr = &brain;
	std::string& brain_ref = brain;

	std::cout 	<< "The memory address of the string variable: " << &brain << std::endl
				<< "The memory address held by stringPTR: " << brain_ptr << std::endl
				<< "The memory address held by stringREF: " << &brain_ref << std::endl
			;

	std::cout 	<< "The value of the string variable: " << brain << std::endl 
				<< "The value pointed to by stringPTR: " << *brain_ptr << std::endl 
				<< "The value pointed to by stringREF: " << brain_ref << std::endl
			;

	return (0);
}