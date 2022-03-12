/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:58:08 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:58:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors & Destructors
AForm::AForm() : _name("AForm"), _required_sign(150), _required_exe(150), _is_signed(false)
{
    return ;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _required_sign(src.getGradeSign()), _required_exe(src.getGradeExe()), _is_signed(src.getIfSigned())
{
	try
	{
		if (this->_required_exe < 1 || this->_required_sign < 1)
			throw AForm::GradeTooHighException();
		if (this->_required_exe > 150 || this->_required_sign > 150)
			throw AForm::GradeTooLowException();
	}
	catch(AForm::GradeTooHighException &e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exe) : _name(name), _required_sign(grade_to_sign), _required_exe(grade_to_exe), _is_signed(false)
{
	try
	{
		if (this->_required_exe < 1 || this->_required_sign < 1)
			throw AForm::GradeTooHighException();
		if (this->_required_exe > 150 || this->_required_sign > 150)
			throw AForm::GradeTooLowException();
	}
	catch(AForm::GradeTooHighException & e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

AForm::~AForm()
{
    return ;
}

//operator overload
AForm &AForm::operator=(AForm const & src)
{
	this->_is_signed = src.getIfSigned();
	return (*this);
}

std::ostream &operator<<( std::ostream &o, AForm const &i)
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
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("'s grade to sign or execute is too high.");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("'s grade to sign or execute is too low.");
}

const char *AForm::FormNotSigned::what() const throw() 
{
	return "'s not signed.";
}

const char *AForm::AlreasdySign::what() const throw() 
{
	return "'s already signed.";
}


//Accessors
std::string AForm::getName() const
{
	return (this->_name);
}

int			AForm::getGradeSign() const
{
	return (this->_required_sign);
}

int			AForm::getGradeExe() const
{
	return (this->_required_exe);
}

bool        AForm::getIfSigned() const
{
	return (this->_is_signed);
}

//Actions
void		AForm::beSigned(Bureaucrat bureau)
{
	try
	{
		if (this->_is_signed == true)
			throw AForm::AlreasdySign();
		else if (this->_required_exe < bureau.getGrade())
			throw AForm::GradeTooLowException();
		else
		{
			this->_is_signed = true;
			std::cout << "AForm " << this->_name << " got signed by " << bureau.getName() << std::endl;
		}
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << bureau.getName() << e.what() << std::endl;
	}
	catch (AForm::AlreasdySign &e)
	{
		std::cout << this->getName() << e.what() << std::endl;
	}
	return ;
}
