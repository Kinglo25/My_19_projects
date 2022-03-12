/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lamephonebook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:31:22 by jandre            #+#    #+#             */
/*   Updated: 2022/01/20 11:44:30 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lamephonebook.hpp"

lame_phone_book::lame_phone_book(void)
{
	std::cout << "*** WELCOME TO THE LAMEST PHONE BOOK EVER!!! ***" << std::endl;
	std::cout << std::endl;
	std::cout << "You have multiple command at your disposal :" << std::endl;
	std::cout << "ADD : to add more friends to your favorite phone book" << std:: endl;
	std::cout << "SEARCH : to know what friends you already have" << std::endl;
	std::cout << "EXIT : to leave your sad phone book :(" << std::endl;
	std::cout << "Important reminder : you cant have more than 8 friends" << std::endl;
	std::cout << std::endl;
	this->number_contact = 0;
	return ;
}

lame_phone_book::~lame_phone_book(void)
{
	std::cout << "Oh already leaving? you will loose all your registered friends..." << std::endl;
	return ;
}

void	lame_phone_book::add_contact(void)
{
	int					i;
	std::string			answer;
	
	if (this->number_contact == 8)
	{
		while (1)
		{
			std::cout << "You already have 8 contact! Do you want to replace one? YES or NO" << std::endl;
			getline(std::cin, answer);
			if (answer == "YES")
			{
				while (1)
				{
					std::cout << "Which contact do you want to replace? 1 is the oldest and 8 is \
the newest one, pick carrefully ;)" << std::endl;
					while (1)
					{
						getline(std::cin, answer);
						std::stringstream tmp(answer);
						if ((tmp >> i) && (i <= 8 && i >= 1))
							break ;
						std::cout << std::endl << "Type a number between 1 and 8 please..." << std::endl;
					}
					std::cout << std::endl;
					contact[i - 1].add_contact();
						break ;
				}
				break ;
			}
			else if (answer == "NO")
				break ;
			else
				std::cout << "Please enter YES or NO" << std::endl;
		}
	}
	else
	{
		i = this->number_contact;
		this->number_contact++;
		contact[i].add_contact();
	}
	return ;
}

void	lame_phone_book::get_contact(int i)
{
	contact[i].get_info();
	return ;
}

void	lame_phone_book::search_contact(void)
{
	int	i;
	std::string	answer;

	i = -1;
	if (this->number_contact == 0)
	{
		std::cout << "You still don't have anybody in your phonebook... Sorry... :(" << std::endl;
		return ;
	}
	else
		std::cout << "     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
	while (++i < this->number_contact)
		contact[i].display_contact(i);
	std::cout << "which contact do you want to examine thoroughly?" << std::endl;
	while (1)
	{
		getline(std::cin, answer);
		std::stringstream tmp(answer);
		if ((tmp >> i) && (i <= this->number_contact && i >= 1))
			break ;
		if (this->number_contact > 1)
			std::cout << std::endl << "Type a number between 1 and " << this->number_contact << " please..." << std::endl;
		else
			std::cout << "Man type 1, you only have one contact... and no funny things!" << std::endl;
	}
	contact[i - 1].get_info();
	return ;
}