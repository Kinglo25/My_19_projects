/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:45 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 19:51:11 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ----------------------------- Constructors ------------------------------ //
ShrubberyCreationForm::ShrubberyCreationForm()
{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Default Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c) 
				: Form(c.get__name(), c.get__grade_sign(), c.get__grade_exec()), target(c.get_target())
{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Copy Constructor");
	*this = c;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string in_target) 
					: Form("ShrubberyCreationForm", 145, 137), target(in_target)
{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	_SHRUBBERYCREATIONFORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& c)
{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Copy Assignement Operator");
	target = c.get_target();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

std::string ShrubberyCreationForm::get_target() const{ return target; }
void ShrubberyCreationForm::set_target(std::string input){ target = input; }


// --------------------------------- Methods ------------------------------- //

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

    if (this->get__signed() == false)
        throw FormNotSignedException();
    if (this->get__grade_exec() < executor.get__grade())
        throw GradeTooLowException();
    std::string filename = target + "_shrubbery";
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