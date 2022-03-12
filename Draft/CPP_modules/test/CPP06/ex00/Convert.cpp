/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:49:54 by jandre            #+#    #+#             */
/*   Updated: 2022/02/01 11:30:37 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

//Constructor & Destructor

Convert::Convert(std::string input) : input(input)
{
    return ;
} 

Convert::Convert(Convert const &src)
{
    *this = src;
    return ;
}

Convert::~Convert()
{
    return ;
}

//operator overload
Convert &Convert::operator=(Convert const & src)
{
    this->input = src.get_input();
	return (*this);
}

//accessors
std::string Convert::get_input() const
{
    return (this->input);
}

//exception
const char *Convert::Impossible::what() const throw()
{
    return ("Impossible");
}

const char *Convert::NotDisplayable::what() const throw()
{
    return ("Not Displayable");
}

//actions
int Convert::is_okay(void) const
{
    if (((this->input.length() != 1) && (this->input.c_str()[0] < '0' || this->input.c_str()[0] > '9') &&
        (this->input.c_str()[0] == '-' && (this->input.c_str()[1] < '0' || this->input.c_str()[1] > '9'))))
    {
        if (this->input == "inf" || this->input == "nan" || this->input == "-inf" ||
            this->input == "inff" || this->input == "-inff" || this->input == "nanf" ||
            this->input == "+inf" || this->input == "+inff")
            return (0);
        return (1);
    }
    return (0); 
}

int Convert::get_precision(void) const
{
    int pos;

    pos = this->input.find(".");
    if (pos == -1)
        return (0);
    
    return (this->input.length() - pos - 1);
}

void Convert::tochar(void) const
{
    double d;
    char c;
    char **end = NULL;

    std::cout << "char: ";
    try
    {
        d = strtod(this->input.c_str(), end);
        if (*input.begin() < '0' || *input.begin() > '9' || d < 0 || d > 255)
            throw(Convert::Impossible());
        if (d < 32 || d > 126)
            throw(Convert::NotDisplayable());
    }
    catch (Convert::Impossible &e)
    {
        if (this->input.length() == 1)
        {
            std::cout << this->input << std::endl;
            return ;
        }
        std::cout << e.what() << std::endl;
        return ;
    }
    catch (Convert::NotDisplayable &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    c = static_cast<char>(d);
    std::cout << "'" << c << "'" << std::endl;
    return ;
}

void Convert::toint(void) const
{
    double d;
    int i;
    char **end = NULL;

    d = strtod(this->input.c_str(), end);
    std::cout << "int : ";
    if (this->input == "0")
    {
        std::cout << "0" << std::endl;
        return ;
    }
    try
    {
        if (this->input == "nan" || this->input == "nanf")
            throw(Convert::Impossible());
        if (d > 2147483647 || d < -2147483648 || d == 0)
            throw(Convert::Impossible());
    }
    catch(const Convert::Impossible &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    i = static_cast<int>(d);
    std::cout << i << std::endl;
    return ;
}

void Convert::tofloat(void) const
{
    double d;
    float f;
    char **end = NULL;

    std::cout << "float : ";
    if (this->input == "0")
    {
        std::cout << "0.0f" << std::endl;
        return ;
    }
    d = strtod(this->input.c_str(), end);
    try
    {
        if (d == 0)
            throw(Convert::Impossible());
    }
    catch(const Convert::Impossible &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    f = static_cast<float>(d);
    std::cout << std::setprecision(this->get_precision()) << std::fixed << f << "f" << std::endl;
    return ;
}

void Convert::todouble(void) const
{
    double d;
    char **end = NULL;

    std::cout << "double : ";
    if (this->input == "0")
    {
        std::cout << "0.0" << std::endl;
        return ;
    }
    d = strtod(this->input.c_str(), end);
    try
    {
        if (d == 0)
            throw(Convert::Impossible());
    }
    catch(const Convert::Impossible &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    std::cout << std::setprecision(this->get_precision()) << std::fixed << d << std::endl;
    return ;
}