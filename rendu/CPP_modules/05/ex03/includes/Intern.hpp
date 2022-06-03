/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:39:10 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 20:59:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
public:
	

// ----------------------------- Constructors ------------------------------ //
	Intern();	// Default Constructor
	Intern(const Intern& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~Intern();	// Destructor

// ------------------------------- Operators ------------------------------- //
	Intern & operator=(const Intern& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	

// --------------------------------- Methods ------------------------------- //

	Form *makeForm(std::string type, std::string target);

private:
    Form* createPresidential(std::string formTarget);
	Form* createRobotomy(std::string formTarget);
	Form* createShrubbery(std::string formTarget);

};

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _INTERN_ARGS ""
#  define _INTERN_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _INTERN_ARGS  \
			  << "}" << std::endl;
# else

#  define _INTERN_AUTO(x, y) ;
#  define _INTERN_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* INTERN_HPP */
