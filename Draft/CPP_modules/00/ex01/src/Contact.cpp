/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:07:16 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/17 14:39:58 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void		Contact::set_first_name()
{
	std::string	input;

	while (true)
	{
		std::cout << "First name (*^▽^*) : ";
		std::getline(std::cin, input);
		if (input != "")
			break ;
		std::cout << "You need to type something, silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
	}
	this->_first_name = input;
	return ;
}

void		Contact::set_last_name()
{
	std::string	input;
	
	while (true)
	{
		std::cout << "Last name ≧(´▽｀)≦ : ";
		std::getline(std::cin, input);
		if (input != "")
			break ;
		std::cout << "You need to type something, silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
	}
	this->_last_name = input;
	return ;
}

void		Contact::set_nickname()
{
	std::string	input;
	
	while (true)
	{
		std::cout << "Nickname ☜(⌒▽⌒)☞ : ";
		std::getline(std::cin, input);
		if (input != "")
			break ;
		std::cout << "You need to type something, silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
	}
	this->_nickname = input;
	return ;
}

void		Contact::set_phone_number()
{
	std::string	input;
	
	while (true)
	{
		std::cout << "(•ˇ‿ˇ•)-→ Phone Number : ";
		std::getline(std::cin, input);
		if (input != "")
			break ;
		std::cout << "You need to type something, silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
	}
	this->_phone_number = input;
	return ;
}

void		Contact::set_darkest_secret()
{
	std::string	input;
	
	while (true)
	{
		std::cout << "Darkest secret !(•̀ᴗ•́)و ̑̑ : ";
		std::getline(std::cin, input);
		if (input != "")
			break ;
		std::cout << "You need to type something, silly ! ﾍ(=￣∇￣)ﾉ" << std::endl;
	}
	this->_darkest_secret = input;
	return ;
}

std::string	Contact::get_first_name() const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name() const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname() const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number() const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret() const
{
	return (this->_darkest_secret);
}