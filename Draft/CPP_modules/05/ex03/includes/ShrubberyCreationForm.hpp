/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:58:30 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 19:49:33 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
public:
	

// ----------------------------- Constructors ------------------------------ //
	ShrubberyCreationForm();	// Default Constructor
	ShrubberyCreationForm(std::string in_target);	// Fields Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~ShrubberyCreationForm();	// Destructor

// ------------------------------- Operators ------------------------------- //
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm& a);
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

#  define _SHRUBBERYCREATIONFORM_ARGS _ARG(target)
#  define _SHRUBBERYCREATIONFORM_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _SHRUBBERYCREATIONFORM_ARGS  \
			  << "}" << std::endl;
# else

#  define _SHRUBBERYCREATIONFORM_AUTO(x, y) ;
#  define _SHRUBBERYCREATIONFORM_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* SHRUBBERYCREATIONFORM_HPP */
