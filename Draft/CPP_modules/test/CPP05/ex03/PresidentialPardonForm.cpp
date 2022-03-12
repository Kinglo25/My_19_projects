/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:05:59 by jandre            #+#    #+#             */
/*   Updated: 2021/12/21 19:24:56 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Constructors & Destructors
PresidentialForm::PresidentialForm(std::string target) : AForm("PresidentialForm", 25, 5), _target(target)
{
    return ;
}

PresidentialForm::PresidentialForm(PresidentialForm const &src) : AForm(src.getName(), 25, 5), _target(src.getTarget())
{
    return ;
}

PresidentialForm::PresidentialForm(std::string target, std::string name) : AForm(name, 25, 5), _target(target)
{
    return ;
}

PresidentialForm::~PresidentialForm()
{
    return ;
}

//Accessors
std::string PresidentialForm::getTarget() const
{
    return (this->_target);
}

//operator overload
PresidentialForm &PresidentialForm::operator=(PresidentialForm const & src)
{
	if (this == &src)
		return (*this);
    AForm::operator=(src);
	return (*this);
}

std::ostream &operator<<(std::ostream &o, PresidentialForm const &i)
{
    std::string sign;

    if (i.getIfSigned() == true)
        sign = "signed";
    else
        sign = "not signed";
	o << i.getName() << " [ " << sign << " | Presidential form | " << i.getGradeSign() << " | " << i.getGradeExe() << " ]";
	return (o);
}

//Actions
void PresidentialForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getIfSigned() == false)
            throw(PresidentialForm::FormNotSigned());
        else if (this->getGradeExe() < executor.getGrade())
            throw(PresidentialForm::GradeTooLowException());
    }
    catch (AForm::GradeTooLowException &e)
	{
		std::cout << executor.getName() << e.what() << std::endl;
        return ;
	}
	catch (AForm::FormNotSigned &e)
	{
		std::cout << this->getName() << e.what() << std::endl;
        return ;
	}
    std::cout << this->_target << " has been excused by Zaafod Beeblebox, be safe." << std::endl;
    return ;
}
