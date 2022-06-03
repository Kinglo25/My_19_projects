/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:33:15 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/31 13:25:51 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

class Form;

class Bureaucrat
{
public:
	struct GradeTooHighException : public std::exception 
	{
		const char* what () const throw ()
		{
			return ("Error : Grade Too High");
		}
	};
	struct GradeTooLowException : public std::exception 
	{
		const char* what () const throw ()
		{
			return ("Error : Grade Too Low");
		}
	};

// ----------------------------- Constructors ------------------------------ //
	Bureaucrat();	// Default Constructor
	Bureaucrat(std::string in__name, int in__grade);	// Fields Constructor
	Bureaucrat(const Bureaucrat& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~Bureaucrat();	// Destructor

// ------------------------------- Operators ------------------------------- //
	Bureaucrat & operator=(const Bureaucrat& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	const std::string get__name() const;
	
	int get__grade() const;
	void set__grade(int input);
	

// --------------------------------- Methods ------------------------------- //

	void increment_grade();
	void decrement_grade();
	void signForm(Form &in);

private:
	const std::string _name;
	int _grade;

};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &in);

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _BUREAUCRAT_ARGS _ARG(_name) << _ARG(_grade)
#  define _BUREAUCRAT_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _BUREAUCRAT_ARGS  \
			  << "}" << std::endl;
# else

#  define _BUREAUCRAT_AUTO(x, y) ;
#  define _BUREAUCRAT_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* BUREAUCRAT_HPP */
