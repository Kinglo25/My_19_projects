/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:06:54 by jandre            #+#    #+#             */
/*   Updated: 2022/01/31 15:48:22 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors & Destructors
RobotomyForm::RobotomyForm(std::string target) : AForm("RobotomyForm", 72, 45), _target(target)
{
    return ;
}

RobotomyForm::RobotomyForm(RobotomyForm const &src) : AForm(src.getName(), 72, 45), _target(src.getTarget())
{
    return ;
}

RobotomyForm::RobotomyForm(std::string target, std::string name) : AForm(name, 72, 45), _target(target)
{
    return ;
}

RobotomyForm::~RobotomyForm()
{
    return ;
}

//Accessors
std::string RobotomyForm::getTarget() const
{
    return (this->_target);
}

//operator overload
RobotomyForm &RobotomyForm::operator=(RobotomyForm const & src)
{
	if (this == &src)
		return (*this);
    AForm::operator=(src);
	return (*this);
}

std::ostream &operator<<(std::ostream &o, RobotomyForm const &i)
{
    std::string sign;

    if (i.getIfSigned() == true)
        sign = "signed";
    else
        sign = "not signed";
	o << i.getName() << " [ " << sign << " | Robotomy form | " << i.getGradeSign() << " | " << i.getGradeExe() << " ]";
	return (o);
}

void RobotomyForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getIfSigned() == false)
            throw(RobotomyForm::FormNotSigned());
        else if (this->getGradeExe() < executor.getGrade())
            throw(RobotomyForm::GradeTooLowException());
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
    srand (time(NULL));
    std::cout << "BRRRrrRRRrRRr ** Bruit de Perceuse ** BRErrrrrrrbBBRrr" << std::endl;
    if (rand()% 2 == 1)
        std::cout << this->getTarget() << " has successfully been Robotomized" << std::endl;
    else
        std::cout << this->getTarget() << " has unfortunately not been Robotomized" << std::endl;
    return ;
}