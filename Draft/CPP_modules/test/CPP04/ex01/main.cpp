/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:44:17 by jandre            #+#    #+#             */
/*   Updated: 2022/01/28 14:43:43 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "-----------TEST DOG CAT AS ANIMAL IF NO LEAK-----------" << std::endl << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();

    std::cout << j->get_type() << " " << std::endl;
    std::cout << i->get_type() << " " << std::endl;
    std::cout << meta->get_type() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    k->makeSound();
    delete meta;
    delete j;
    delete i;
    delete k;
    
    std::cout << std::endl << "-----------TEST ARRAY AND DESTRUCT-----------" << std::endl << std::endl;
    int num_animals = 10;
	int index = 0;
	Animal *animals[num_animals];
	for ( ; index < num_animals / 2; index++)
    {   
        std::cout << index << " : ";
		animals[index] = new Dog;
    }
	for ( ; index < num_animals; index++)
    {
        std::cout << index << " : ";
		animals[index] = new Cat;
    }
	for (index = 0; index < num_animals; index++)
    {
        std::cout << index << " : ";
		delete animals[index];
    }

    std::cout << std::endl << "-----------TEST DEEP COPY-----------" << std::endl << std::endl;
    Dog *toutou1 = new Dog();
    Dog *toutou2 = new Dog();
    Dog *toutou3 = new Dog();
    Dog *toutou4 = new Dog(*toutou2);
    Cat *matou1 = new Cat();
    Cat *matou2 = new Cat();
    Cat *matou3 = new Cat();
    Cat *matou4 = new Cat(*matou2);


    *toutou3 = *toutou2;
    *matou3 = *matou2;
    std::cout << "IDEA 1 TOUTOU1 : " << toutou1->get_idea(0) << std::endl;
    std::cout << "IDEA 1 TOUTOU2 : " << toutou2->get_idea(0) << std::endl;    
    std::cout << "IDEA 1 TOUTOU3 : " << toutou3->get_idea(0) << std::endl;    
    std::cout << "IDEA 1 TOUTOU4 : " << toutou4->get_idea(0) << std::endl;    
    *toutou2 = *toutou1;
    std::cout << "IDEA 1 AFTER COPY TOUTOU1 : " << toutou1->get_idea(0) << std::endl;
    std::cout << "IDEA 1 AFTER COPY TOUTOU2 : " << toutou2->get_idea(0) << std::endl;
    std::cout << "IDEA 1 MATOU1 : " << matou1->get_idea(0) << std::endl;
    std::cout << "IDEA 1 MATOU2 : " << matou2->get_idea(0) << std::endl;    
    std::cout << "IDEA 1 MATOU3 : " << matou3->get_idea(0) << std::endl;    
    std::cout << "IDEA 1 MATOU4 : " << matou4->get_idea(0) << std::endl;    
    *matou2 = *matou1;
    std::cout << "IDEA 1 AFTER COPY MATOU1 : " << matou1->get_idea(0) << std::endl;
    std::cout << "IDEA 1 AFTER COPY MATOU2 : " << matou2->get_idea(0) << std::endl;
    delete(toutou1);
    delete(toutou2);    
    delete(toutou3);
    delete(toutou4);
    delete(matou1);    
    delete(matou2);
    delete(matou3);
    delete(matou4);
    return (0);
}