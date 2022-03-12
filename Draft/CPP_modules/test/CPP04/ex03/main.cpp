/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:09:45 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 18:37:20 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    //Class Character test
    Character *me = new Character("me");
    Character *bob = new Character("bob");
    Character *bob_cpy = new Character("John");
    Character *test = new Character("test");
    Character *test_cpy = new Character(*test);

    *bob_cpy = *me;
    std::cout << std::endl;
    std::cout << "Test l'operator overload '=' : " << bob_cpy->getName() << std::endl;
    std::cout << "Test constructor by copy : " << std::endl << test->getName() << std::endl;
    std::cout << test_cpy->getName() << std::endl;
    std::cout << std::endl;
    
    //Test Materia Source
    MateriaSource* src = new MateriaSource();
    MateriaSource* src2 = new MateriaSource();
    src->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src2->learnMateria(new Ice());
    std::cout << std::endl;

    //Test creation Materia
    AMateria *tmp = src->createMateria("ice");
    AMateria *tmp2 = src->createMateria("cure");
    AMateria *tmp3 = src->createMateria("cure");
    AMateria *tmp4 = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp2);
    me->equip(tmp3);
    me->equip(tmp4);
    me->equip(tmp);
    std::cout << me->getMateria(0)->getType() << std::endl;
    std::cout << me->getMateria(1)->getType() << std::endl;
    std::cout << me->getMateria(2)->getType() << std::endl;
    std::cout << me->getMateria(3)->getType() << std::endl << std::endl;
    //Using Materia equiped
    me->use(0, *bob);
    me->use(1, *bob);
    bob->use(3, *me);
    std::cout << std::endl;
    bob->equip(tmp2);
    std::cout << bob->getMateria(0)->getType() << std::endl;
    *bob = *me;
    me->unequip(0);
    me->equip(tmp2);
    std::cout << me->getMateria(0)->getType() << std::endl;
    std::cout << bob->getMateria(0)->getType() << std::endl;
    bob->unequip(0);
    bob->equip(tmp);
    std::cout << me->getMateria(0)->getType() << std::endl;
    std::cout << bob->getMateria(0)->getType() << std::endl;
    std::cout << std::endl;
    
    //Test operator overload && constructor copy
    *src2 = *src;
    
    delete tmp;
    delete tmp2;
    delete tmp3;
    delete tmp4;
    delete me;
    delete bob;
    delete bob_cpy;
    delete test;
    delete test_cpy;
    delete src;
    delete src2;
    return 0;
}