/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:05:59 by jandre            #+#    #+#             */
/*   Updated: 2021/12/23 16:33:49 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialForm : public AForm {
    private:
        const std::string _target;
    public:
    //Constructor & Destructors
        PresidentialForm(std::string target);
		PresidentialForm(PresidentialForm const &src);
		PresidentialForm(std::string target, std::string name);
		virtual ~PresidentialForm();
    
    //Accessors
        std::string getTarget() const;
    
    //operator
        PresidentialForm &operator=(PresidentialForm const & src);
    
    //Actions
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialForm const &i);

#endif