/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:16:42 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/17 17:15:34 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	add_contact(PhoneBook *Pb)
{
	Contact		contact;

	contact.set_first_name();
	contact.set_last_name();
	contact.set_nickname();
	contact.set_phone_number();
	contact.set_darkest_secret();
	Pb->set_contact(contact);
	return ;
}

void	search_contact(PhoneBook *Pb)
{
	int		index;
	int		count;
	Contact	contact;

	index = 0;
	count = Pb->get_count();
	while (index < count)
	{
		contact = Pb->get_contact(index);
		std::cout << std::left << std::setfill('.') << std::setw(10);
		std::cout << contact.get_first_name() << '|';
		std::cout << contact.get_last_name() << '|';
		index++;
	}
}

int	main(void)
{
	PhoneBook	Pb;
	std::string	command;

	std::cout << "Here are the ruWules : (◍•ᴗ•◍)❤" << std::endl;
	std::cout << "\'ADD\': save a new contact. (｡･ω･｡)" << std::endl;
	std::cout << "\'SEARCH\': display a specific contact. (n˘v˘•)¬" << std::endl;
	std::cout << "\'EXIT\': The program quits and the contacts are lost forever! (′ʘ⌄ʘ‵)" << std::endl;
	std::cout << "/!\\ Any other input will be discarded. (ᅌᴗᅌ* )/!\\" << std::endl;

	while (true)
	{
		std::cout << "Please, enter your command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			add_contact(&Pb);
		if (command == "SEARCH")
			search_contact(&Pb);
		if (command == "EXIT")
			break ;	
	}
	return (0);
}