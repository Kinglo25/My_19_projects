/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:41 by lmajerus          #+#    #+#             */
/*   Updated: 2022/04/20 16:11:24 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const Animal* i = new Cat("Siamese");
	const Animal* j = new Dog("Golden Retriever");
	const WrongAnimal* k = new WrongCat();
	const WrongCat* l = new WrongCat("Black Tabby");

	std::cout << std::endl << i->get_type() << " " << std::endl;
	std::cout << j->get_type() << " " << std::endl;
	std::cout << k->get_type() << " " << std::endl;
	std::cout << l->get_type() << " " << std::endl << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	Wrongmeta->makeSound();
	std::cout << std::endl;
	k->makeSound();
	l->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
}