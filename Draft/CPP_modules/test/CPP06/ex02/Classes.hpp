/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:58:18 by jandre            #+#    #+#             */
/*   Updated: 2022/01/20 16:25:16 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP
# include <iostream>
# include <stdlib.h>
# include <time.h>

class Base {

public:
    virtual ~Base();
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};


#endif