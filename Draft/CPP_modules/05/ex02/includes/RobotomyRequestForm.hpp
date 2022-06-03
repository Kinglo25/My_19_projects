/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:58:46 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 19:44:24 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	

// ----------------------------- Constructors ------------------------------ //
	RobotomyRequestForm();	// Default Constructor
	RobotomyRequestForm(std::string in_target);	// Fields Constructor
	RobotomyRequestForm(const RobotomyRequestForm& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~RobotomyRequestForm();	// Destructor

// ------------------------------- Operators ------------------------------- //
	RobotomyRequestForm & operator=(const RobotomyRequestForm& a);
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

#  define _ROBOTOMYREQUESTFORM_ARGS _ARG(target)
#  define _ROBOTOMYREQUESTFORM_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _ROBOTOMYREQUESTFORM_ARGS  \
			  << "}" << std::endl;
# else

#  define _ROBOTOMYREQUESTFORM_AUTO(x, y) ;
#  define _ROBOTOMYREQUESTFORM_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* ROBOTOMYREQUESTFORM_HPP */
