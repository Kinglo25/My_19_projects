/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:20:22 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 16:53:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
# define MATERIASOURCE
# include "AbstractClasses.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria    *materia[4];

    public:
        //Constructors & Destructors
        MateriaSource(void);
        MateriaSource(MateriaSource const &copy);
        ~MateriaSource(void);

        //opperators
        MateriaSource &operator=(const MateriaSource &rhs);

        //Accessors
        AMateria *getMateria(int index) const;

        //Actions
        void learnMateria(AMateria* m);
	    AMateria* createMateria(std::string const &type);
};

#endif