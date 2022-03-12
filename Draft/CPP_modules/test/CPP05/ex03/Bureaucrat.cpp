/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:43:56 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:58:51 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors & Destructors
Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src.getName()), _grade(src.getGrade())
{
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

//operator overload
Bureaucrat &Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src.getGrade();
	return (*this);
}

std::ostream &operator<<( std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << " [ " << i.getGrade() << " ]";
	return (o);
}

//exception
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("'s grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("'s grade is too low.");
}

const char *Bureaucrat::FormNotSigned::what() const throw() 
{
	return "'s not signed.";
}

const char *Bureaucrat::AlreasdySign::what() const throw() 
{
	return "'s already signed.";
}

//Accessors
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//Actions
void	Bureaucrat::incGrade()
{
	try {
		this->_grade--;
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
    catch (Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

void	Bureaucrat::decGrade()
{
	try {
		this->_grade++;
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		this->_grade = 1;
		std::cout << this->_name << e.what() << std::endl;
	}
    catch (Bureaucrat::GradeTooLowException &e)
	{
		this->_grade = 150;
		std::cout << this->_name << e.what() << std::endl;
	}
    return ;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
    {
        if (form.getIfSigned() == true)
            throw(Bureaucrat::AlreasdySign());
        else if (this->getGrade() > form.getGradeSign())
            throw(Bureaucrat::GradeTooLowException());
    }
    catch (Bureaucrat::AlreasdySign &e)
	{
		std::cout << form.getName() << e.what() << std::endl;
        return ;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << this->getName() << e.what() << std::endl;
        return ;
	}
	form.beSigned(*this);
	return ;
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
    {
        if (form.getIfSigned() == false)
            throw(Bureaucrat::FormNotSigned());
        else if (this->getGrade() > form.getGradeExe())
            throw(Bureaucrat::GradeTooLowException());
    }
    catch (Bureaucrat::FormNotSigned &e)
	{
		std::cout << form.getName() << e.what() << std::endl;
        return ;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << this->getName() << e.what() << std::endl;
        return ;
	}
	form.execute(*this);
	return ;
}