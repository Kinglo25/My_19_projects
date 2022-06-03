/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:51:59 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 19:53:31 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ----------------------------- Constructors ------------------------------ //
PresidentialPardonForm::PresidentialPardonForm()
{
	_PRESIDENTIALPARDONFORM_AUTO(32, "Default Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c) 
					: Form(c.get__name(), c.get__grade_sign(), c.get__grade_exec()), target(c.target)
{
	_PRESIDENTIALPARDONFORM_AUTO(32, "Copy Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(std::string in_target) 
				: Form("PresidentialPardonForm", 25, 5), target(in_target)
{
	_PRESIDENTIALPARDONFORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
PresidentialPardonForm::~PresidentialPardonForm()
{
	_PRESIDENTIALPARDONFORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& c)
{
	_PRESIDENTIALPARDONFORM_AUTO(32, "Copy Assignement Operator");
	target = c.target;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

std::string PresidentialPardonForm::get_target() const{ return target; }
void PresidentialPardonForm::set_target(std::string input){ target = input; }

// --------------------------------- Methods ------------------------------- //

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->get__signed() == false)
        throw FormNotSignedException();
    if (this->get__grade_exec() < executor.get__grade())
        throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}