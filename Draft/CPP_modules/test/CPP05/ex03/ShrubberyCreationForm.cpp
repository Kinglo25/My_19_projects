/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:07:13 by jandre            #+#    #+#             */
/*   Updated: 2021/12/23 16:08:27 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Constructors & Destructors
ShrubberyForm::ShrubberyForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target(target)
{
    return ;
}

ShrubberyForm::ShrubberyForm(ShrubberyForm const &src) : AForm(src.getName(), 145, 137), _target(src.getTarget())
{
    return ;
}

ShrubberyForm::ShrubberyForm(std::string target, std::string name) : AForm(name, 145, 137), _target(target)
{
    return ;
}

ShrubberyForm::~ShrubberyForm()
{
    return ;
}

//Accessors
std::string ShrubberyForm::getTarget() const
{
    return (this->_target);
}

//operator overload
ShrubberyForm &ShrubberyForm::operator=(ShrubberyForm const &src)
{
	if (this == &src)
		return (*this);
    AForm::operator=(src);
	return (*this);
}

std::ostream &operator<<(std::ostream &o, ShrubberyForm const &i)
{
    std::string sign;

    if (i.getIfSigned() == true)
        sign = "signed";
    else
        sign = "not signed";
	o << i.getName() << " [ " << sign << " | Schrubbery form | " << i.getGradeSign() << " | " << i.getGradeExe() << " ]";
	return (o);
}

void ShrubberyForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getIfSigned() == false)
            throw(ShrubberyForm::FormNotSigned());
        else if (this->getGradeExe() < executor.getGrade())
            throw(ShrubberyForm::GradeTooLowException());
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
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str(), std::ios::app);
    outfile << "\
           ___\n\
           IOI\n\
          IOOOI\n\
        IO0O0O0OI\n\
        IO0O0O0O0I\n\
         I0O0O0OI\n\
          I0O0I\n\
           |1|\n\
           |1|\n\
           |1|\n\
           |||\n\
        &&__|__&&\n" << std::endl;
    outfile.close();
    return ;
}