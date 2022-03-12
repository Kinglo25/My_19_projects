/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:16:42 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/12 16:01:33 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook Pb;

	std::cout << "Hi! Enter:" << std::endl;
	std::cout << "\'ADD\': save new contact" << std::endl;
	std::cout << "\'SEARCH\': display a specific contact" << std::endl;
	std::cout << "\'EXIT\': The program quits and the contacts are lost forever!" << std::endl;
	std::cout << "Any other input will be discarded." << std::endl;
	
	return (0);
}