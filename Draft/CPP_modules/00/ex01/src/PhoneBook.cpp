/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:06:36 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/17 17:13:26 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::set_contact(Contact contact)
{
	this->_contact[this->_count] = contact;
	this->_count++;
	this->_count %= 8;
}

int		PhoneBook::get_count() const
{
	return (this->_count);
}

Contact PhoneBook::get_contact(int i) const
{
	return (this->_contact[i]);
}