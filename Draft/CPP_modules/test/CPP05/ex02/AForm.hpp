/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:57:58 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:58:02 by jandre           ###   ########.fr       */
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
		~AForm();

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