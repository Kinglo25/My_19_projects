/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:05:02 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:58:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyForm : public AForm {
    private:
        std::string const _target;
    public:
    //Constructor & Destructors
        ShrubberyForm(std::string target);
		ShrubberyForm(ShrubberyForm const &src);
		ShrubberyForm(std::string target, std::string name);
		~ShrubberyForm();

    //operator
        ShrubberyForm &operator=(ShrubberyForm const & src);
    
    //Accessors
        std::string getTarget() const;
        
    //Actions
        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyForm const &i);

#endif