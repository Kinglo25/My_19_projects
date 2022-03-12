/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:34:57 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:55:53 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors & Destructors
Form::Form() : _name("Form"), _required_sign(150), _required_exe(150), _is_signed(false)
{
    return ;
}

Form::Form( Form const & src ) : _name(src.getName()), _required_sign(src.getGradeSign()), _required_exe(src.getGradeExe()), _is_signed(getIfSigned())
{
	try
	{
		if (this->_required_exe < 1 || this->_required_sign < 1)
			throw Form::GradeTooHighException();
		if (this->_required_exe > 150 || this->_required_sign > 150)
			throw Form::GradeTooLowException();
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exe) : _name(name), _required_sign(grade_to_sign), _required_exe(grade_to_exe), _is_signed(false)
{
	try
	{
		if (this->_required_exe < 1 || this->_required_sign < 1)
			throw Form::GradeTooHighException();
		if (this->_required_exe > 150 || this->_required_sign > 150)
			throw Form::GradeTooLowException();
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

Form::~Form()
{
    return ;
}

//operator overload
Form &Form::operator=(Form const & src)
{
	this->_is_signed = src.getIfSigned();
	return (*this);
}

std::ostream &operator<<( std::ostream &o, Form const &i)
{
    std::string sign;

    if (i.getIfSigned() == true)
        sign = "signed";
    else
        sign = "not signed";
	o << i.getName() << " is " << sign << " and form grade to sign is " << i.getGradeSign() << " and to execute is " << i.getGradeExe();
	return (o);
}

//exception
const char*	Form::GradeTooHighException::what() const throw()
{
	return ("'s grade to sign or execute is too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("'s grade to sign or execute is too low.");
}

//Accessors
std::string Form::getName() const
{
	return (this->_name);
}

int			Form::getGradeSign() const
{
	return (this->_required_sign);
}

int			Form::getGradeExe() const
{
	return (this->_required_exe);
}

bool        Form::getIfSigned() const
{
	return (this->_is_signed);
}

//Actions
void		Form::beSigned(Bureaucrat bureau)
{
	if (this->_is_signed == true)
	{
		std::cout << "The form : " << this->_name << " is already signed." << std::endl;
		return ;
	}
	try
	{
		if (this->_required_exe < bureau.getGrade())
			throw Form::GradeTooLowException();
		else
		{
			this->_is_signed = true;
			std::cout << "Form " << this->_name << " got signed by " << bureau.getName() << std::endl;
		}
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << bureau.getName() << e.what() << std::endl;
	}
	return ;
}
