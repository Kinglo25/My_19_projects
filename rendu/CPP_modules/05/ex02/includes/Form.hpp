/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:38:36 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/30 20:38:37 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
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
	struct FormNotSignedException : public std::exception 
	{
		const char* what () const throw ()
		{
			return ("Error : Form Not Signed");
		}
	};

// ----------------------------- Constructors ------------------------------ //
	Form();	// Default Constructor
	Form(std::string in__name, int in__grade_sign, int in__grade_exec);	// Fields Constructor
	Form(const Form& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	virtual ~Form();	// Destructor

// ------------------------------- Operators ------------------------------- //
	Form & operator=(const Form& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	const std::string get__name() const;
	void set__name(const std::string input);
	
	bool get__signed() const;
	void set__signed(bool input);
	
	int get__grade_sign() const;
	void set__grade_sign(const int input);
	
	int get__grade_exec() const;
	void set__grade_exec(const int input);
	

// --------------------------------- Methods ------------------------------- //

	void beSigned(Bureaucrat &in);
	virtual void execute(Bureaucrat const &executor) const = 0;

private:
	const std::string _name;
	bool _signed;
	const int _grade_sign;
	const int _grade_exec;

};

std::ostream &operator<<(std::ostream &o, const Form &in);

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _FORM_ARGS _ARG(_name) << _ARG(_signed) << _ARG(_grade_sign) << _ARG(_grade_exec)
#  define _FORM_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _FORM_ARGS  \
			  << "}" << std::endl;
# else

#  define _FORM_AUTO(x, y) ;
#  define _FORM_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* FORM_HPP */
