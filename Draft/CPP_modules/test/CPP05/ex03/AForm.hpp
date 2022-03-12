/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:18:45 by jandre            #+#    #+#             */
/*   Updated: 2021/12/21 16:37:59 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string const   _name;
        int const           _required_sign;
        int const           _required_exe;
        bool                _is_signed;
    public:
        //Destructor & Constructor
        AForm();
		AForm(AForm const &src);
		AForm(std::string name, int grade_to_sign, int grade_to_exe);
		virtual ~AForm();

        //Exception class
        class GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw();
		};
        class FormNotSigned : public std::exception 
		{
            public:
			    const char *what() const throw();
		};
		
		class AlreasdySign : public std::exception 
		{
            public:
			    const char *what() const throw();
		};

        //Accessors
        std::string getName() const;
		int			getGradeSign() const;
		int			getGradeExe() const;
        bool        getIfSigned() const;

        //operator
        AForm & operator=(AForm const & src);

        //Action
        void beSigned(Bureaucrat bureau);
        virtual void execute(const Bureaucrat &executor) const = 0;

};

std::ostream &			operator<<(std::ostream &o, AForm const &i);

#endif