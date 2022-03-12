/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:50:58 by jandre            #+#    #+#             */
/*   Updated: 2022/01/31 15:54:28 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
    public:
        //Destructor & Constructor
        Intern();
		Intern(Intern const &src);
		~Intern();

        //operator
        Intern &operator=(const Intern &b);

        //Actions
        AForm *makeForm(std::string type, std::string target);
        AForm* createPresidential(std::string formTarget);
        AForm* createRobotomy(std::string formTarget);
        AForm* createShrubbery(std::string formTarget);
        
};

#endif