/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:58:23 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 19:44:32 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"


class PresidentialPardonForm : public Form
{
public:
	

// ----------------------------- Constructors ------------------------------ //
	PresidentialPardonForm();	// Default Constructor
	PresidentialPardonForm(std::string in_target);	// Fields Constructor
	PresidentialPardonForm(const PresidentialPardonForm& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~PresidentialPardonForm();	// Destructor

// ------------------------------- Operators ------------------------------- //
	PresidentialPardonForm & operator=(const PresidentialPardonForm& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	std::string get_target() const;
	void set_target(std::string input);
	

// --------------------------------- Methods ------------------------------- //

	void execute(Bureaucrat const &executor) const;

private:
	std::string target;

};

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _PRESIDENTIALPARDONFORM_ARGS _ARG(target)
#  define _PRESIDENTIALPARDONFORM_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _PRESIDENTIALPARDONFORM_ARGS  \
			  << "}" << std::endl;
# else

#  define _PRESIDENTIALPARDONFORM_AUTO(x, y) ;
#  define _PRESIDENTIALPARDONFORM_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* PRESIDENTIALPARDONFORM_HPP */
