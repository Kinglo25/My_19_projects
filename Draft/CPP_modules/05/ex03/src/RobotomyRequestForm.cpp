/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:43:44 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 19:51:39 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// ----------------------------- Constructors ------------------------------ //
RobotomyRequestForm::RobotomyRequestForm()
{
	_ROBOTOMYREQUESTFORM_AUTO(32, "Default Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c) 
				: Form(c.get__name(), c.get__grade_sign(), c.get__grade_exec()), target(c.target)
{
	_ROBOTOMYREQUESTFORM_AUTO(32, "Copy Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(std::string in_target) 
				: Form("RobotomyRequestForm", 72, 45), target(in_target)
{
	_ROBOTOMYREQUESTFORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
RobotomyRequestForm::~RobotomyRequestForm()
{
	_ROBOTOMYREQUESTFORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& c)
{
	_ROBOTOMYREQUESTFORM_AUTO(32, "Copy Assignement Operator");
	target = c.target;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

std::string RobotomyRequestForm::get_target() const{ return target; }
void RobotomyRequestForm::set_target(std::string input){ target = input; }


// --------------------------------- Methods ------------------------------- //

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->get__signed() == false)
        throw FormNotSignedException();
    if (this->get__grade_exec() < executor.get__grade())
        throw GradeTooLowException();
	std::cout << "Makes some drilling noises." << std::endl;
	if (rand() % 2 == 1)
		std::cout << target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}