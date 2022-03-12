/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:24:29 by jandre            #+#    #+#             */
/*   Updated: 2022/01/20 15:17:35 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <cstdlib>
# include <stdexcept>
# include <cmath>
# include <ctgmath>

class Convert {
    private:
    std::string input;
    
    public:
    //Destructor & Constructor
    Convert(std::string input);
    Convert(Convert const &src);
    ~Convert();
    
    //exception
    class Impossible : std::exception
    {
        public:
            const char *what() const throw();
    };
    class NotDisplayable : std::exception
    {
        public:
            const char *what() const throw();
    };
    
    //operator
    Convert & operator=(Convert const & src);

    //accessors
    std::string get_input(void) const;

    //actions
    int  is_okay(void) const;
    int  get_precision(void) const;
    void tochar(void) const;
    void toint(void) const;
    void tofloat(void) const;
    void todouble(void) const;
};

#endif