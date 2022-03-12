/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:38:49 by jandre            #+#    #+#             */
/*   Updated: 2022/01/20 11:56:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

contact::contact(void)
{
    return ;
}

contact::~contact(void)
{
    return ;
}

void	contact::get_info(void)
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

void	contact::add_contact(void)
{
	std::cout << "Answer question about the new contact please:" << std::endl << std::endl;
	std::cout << "What is the first name of the contact?" << std::endl;
	getline(std::cin, this->first_name);
	std::cout << "What is the last name of the contact?" << std::endl;
	getline(std::cin, this->last_name);
	std::cout << "What is the nickname of the contact?" << std::endl;
	getline(std::cin, this->nickname);
	std::cout << "What is the phone number of the contact?" << std::endl;
	getline(std::cin, this->phone_number);
	std::cout << "What is the darkest secret of the contact?" << std::endl;
	getline(std::cin, this->darkest_secret);
	std::cout << "You have a new contact! Congrats :)" << std::endl;
}


void	contact::display_contact(int i)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;

	first_name = this->first_name;
	last_name = this->last_name;
	nickname = this->nickname;

	if (first_name.length() >= 10)
		first_name.resize (9);
	if (last_name.length() >= 10)
		last_name.resize (9);
	if (nickname.length() >= 10)
		nickname.resize (9);
	std::cout << "         " << i + 1 << "|";
	std::cout << std::setw(10) << first_name << "|";
	std::cout << std::setw(10) << last_name << "|";
	std::cout << std::setw(10) << nickname << "|";
	std::cout << std::endl;
	return ;
}