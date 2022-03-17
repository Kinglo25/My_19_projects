/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:15:16 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/17 17:10:58 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <Contact.hpp>

class PhoneBook
{
public:
		
// Constructors & Destructor
	PhoneBook();
	~PhoneBook();

// Setters
	void	set_contact(Contact contact);
	
// Getters
	int		get_count() const;
	Contact	get_contact(int index) const; 

private:
	int			_count;
	Contact 	_contact[8];
};

#endif