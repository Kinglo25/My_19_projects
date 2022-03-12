/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:05:19 by jandre            #+#    #+#             */
/*   Updated: 2021/12/23 16:33:31 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyForm : public AForm {
    private:
        std::string const _target;
    public:
    //Constructor & Destructors
        RobotomyForm(std::string target);
		RobotomyForm(RobotomyForm const &src);
		RobotomyForm(std::string target, std::string name);
		virtual ~RobotomyForm();

    //Accessors
        std::string getTarget() const;
    
    //operator
        RobotomyForm &operator=(RobotomyForm const & src);

    //Actions
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyForm const &i);

#endif