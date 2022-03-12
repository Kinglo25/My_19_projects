/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractClasses.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:21:37 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 16:22:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT
# define ABSTRACT
# include <iostream>

class AMateria;
class ICharacter;
class IMateriaSource;

class AMateria
{
    protected:
    std::string type;

    public:
    //Constructor Destructor
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(AMateria const &copy);
    virtual ~AMateria();

    //Operators
    AMateria    &operator=(AMateria const &rhs);

    //Accessors
    std::string const & getType(void) const;

    //Actions
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);
};

class ICharacter
{
    public:
    //Destructor
    virtual~ICharacter() {}

    //Accessors
    virtual std::string const & getName() const = 0;
    
    //Actions
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource
{
	public:
	//Destructor
	virtual ~IMateriaSource() {}

    //Actions
    virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif