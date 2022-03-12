/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lamephonebook.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:30:58 by jandre            #+#    #+#             */
/*   Updated: 2021/07/29 16:10:09 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAME_PHONE_BOOK_H
# define LAME_PHONE_BOOK_H
# include "contact.hpp"

class   lame_phone_book
{
    public:
    
    lame_phone_book(void);
    ~lame_phone_book(void);
    
    void    add_contact(void);
    void    get_contact(int i);
    void    search_contact(void);
    
    private:
    
    contact contact[8];
    int     number_contact;
    
};

#endif