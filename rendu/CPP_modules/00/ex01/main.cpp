/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:16:42 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/08 18:24:17 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <climits>

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

std::string	truncate(std::string str)
{

	if (str.length() >= 10)
	{
		str = str.substr(0 , 9) + ".";
	}
	return (str);
	
}

void	search_contact(PhoneBook *Pb)
{
	int		index;
	int		count;
	Contact	contact;

	index = 1;
	count = Pb->get_count();
	if (!count)
	{
		std::cout << "Table is empty, silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
		return ;
	}
	count > 8 ? count = 8 : count;
	std::cout << std::setw(10) << std::right << "Index";
	std::cout << '|' << std::setw(10) << std::right << "First name";
	std::cout << '|' << std::setw(10) << std::right << "Last name";
	std::cout << '|' << std::setw(10) << std::right << "Nickname" << std::endl;
	while (index <= count)
	{
		contact = Pb->get_contact(index - 1);
		std::cout << std::right << std::setw(10) << index << '|';
		std::cout << std::right << std::setw(10) << truncate(contact.get_first_name()) << '|';
		std::cout << std::right << std::setw(10) << truncate(contact.get_last_name()) << '|';
		std::cout << std::right << std::setw(10) << truncate(contact.get_nickname()) << std::endl;
		index++;
	}
	while (true)
	{
		std::cout << "Please enter the index of the contact you want to know more about (n˘v˘•)¬ :";
		std::cin >> index; 
		if (index > count || index < 1)
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "You need to enter a number between 1 and " << count << ", silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
			continue ;
		}
		contact = Pb->get_contact(index - 1);
		std::cout << "First name: " << contact.get_first_name() << std::endl;
		std::cout << "Last name: " << contact.get_last_name() << std::endl;
		std::cout << "Nickname: " << contact.get_nickname() << std::endl;
		std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
		break ;
	}
	std::cin.ignore(INT_MAX, '\n');

}

int	main(void)
{
	PhoneBook	Pb;
	std::string	command;

	std::cout << "Here are the ruWules : (◍•ᴗ•◍)❤" << std::endl << std::endl;
	std::cout << "\'ADD\': save a new contact. (｡･ω･｡)" << std::endl;
	std::cout << "\'SEARCH\': display a specific contact. ヾ(o✪‿✪o)ｼ" << std::endl;
	std::cout << "\'EXIT\': The program quits and the contacts are lost forever! (′ʘ⌄ʘ‵)" << std::endl << std::endl;
	std::cout << "/!\\ Any other input will be discarded. (ᅌᴗᅌ* )/!\\" << std::endl;

	while (true)
	{
		std::cout << "Please, enter your command (n˘v˘•)¬ : ";
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