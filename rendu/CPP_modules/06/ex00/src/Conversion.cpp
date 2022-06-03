/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:22:19 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/01 15:45:09 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

// ----------------------------- Constructors ------------------------------ //
Conversion::Conversion()
{
	_CONVERSION_AUTO(32, "Default Constructor");
}

Conversion::Conversion(const Conversion& c) : input(c.input)
{
	_CONVERSION_AUTO(32, "Copy Constructor");
	*this = c;
}

Conversion::Conversion(std::string in_input) : input(in_input)
{
	_CONVERSION_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Conversion::~Conversion()
{
	_CONVERSION_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Conversion & Conversion::operator=(const Conversion& c)
{
	_CONVERSION_AUTO(32, "Copy Assignement Operator");
	input = c.input;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string Conversion::get_input() const{ return input; }
//void Conversion::set_input(std::string input){ input = input; }



// --------------------------------- Methods ------------------------------- //

int Conversion::is_okay(void) const
{
    if (this->input.length() != 1 && ((this->input[0] == '-' && (this->input[1] < '0' || this->input[1] > '9')) ||
		((this->input[0] != '-' && this->input[0] != '+') && (this->input[0] < '0' || this->input[0] > '9'))))
    {
        if (this->input == "inf" || this->input == "nan" || this->input == "-inf" ||
            this->input == "inff" || this->input == "-inff" || this->input == "nanf" ||
            this->input == "+inf" || this->input == "+inff")
            return (0);
        return (1);
    }
    return (0); 
}

int Conversion::get_precision(void) const
{
    int pos;

    pos = this->input.find(".");
    if (pos == -1)
        return (0);
	if (*this->input.begin() == '-')
		pos+=2;
	if (*this->input.begin() == '+')
		pos++;
	if (*this->input.end() == 'f')
   		return (this->input.length() - pos - 1);
	return (this->input.length() - pos);
}

void Conversion::tochar(void) const
{
    double d;
    char c;

    std::cout << "char: ";
    try
    {
        d = strtod(this->input.c_str(), NULL);
        if (*input.begin() < '0' || *input.begin() > '9' || d < 0 || d > 255)
            throw(Conversion::Impossible());
        if (d < 32 || d > 126)
            throw(Conversion::NotDisplayable());
    }
    catch (Conversion::Impossible &e)
    {
        if (this->input.length() == 1)
        {
            std::cout << "'" << this->input << "'" << std::endl;
            return ;
        }
        std::cout << e.what() << std::endl;
        return ;
    }
    catch (Conversion::NotDisplayable &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    c = static_cast<char>(d);
    std::cout << "'" << c << "'" << std::endl;
    return ;
}

void Conversion::toint(void) const
{
    double d;
    int i;

    d = strtod(this->input.c_str(), NULL);
    std::cout << "int : ";
    if (this->input == "0")
    {
        std::cout << "0" << std::endl;
        return ;
    }
    try
    {
        if (this->input == "nan" || this->input == "nanf")
            throw(Conversion::Impossible());
        if (d > 2147483647 || d < -2147483648 || d == 0)
            throw(Conversion::Impossible());
    }
    catch(const Conversion::Impossible &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    i = static_cast<int>(d);
    std::cout << i << std::endl;
    return ;
}

void Conversion::tofloat(void) const
{
    double d;
    float f;

    std::cout << "float : ";
    if (this->input == "0")
    {
        std::cout << "0.0f" << std::endl;
        return ;
    }
    d = strtod(this->input.c_str(), NULL);
    try
    {
        if (d == 0)
            throw(Conversion::Impossible());
    }
    catch(const Conversion::Impossible &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    f = static_cast<float>(d);
    std::cout << std::setprecision(this->get_precision()) << std::fixed << f << "f" << std::endl;
    return ;
}

void Conversion::todouble(void) const
{
    double d;

    std::cout << "double : ";
    if (this->input == "0")
    {
        std::cout << "0.0" << std::endl;
        return ;
    }
    d = strtod(this->input.c_str(), NULL);
    try
    {
        if (d == 0)
            throw(Conversion::Impossible());
    }
    catch(const Conversion::Impossible &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    std::cout << std::setprecision(this->get_precision()) << std::fixed << d << std::endl;
    return ;
}