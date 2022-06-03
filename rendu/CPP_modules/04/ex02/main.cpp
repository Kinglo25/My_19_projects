/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:41 by lmajerus          #+#    #+#             */
/*   Updated: 2022/05/20 18:41:47 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout	<< "I am a " << meta[i]->get_type() << ": ";
		meta[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

	Dog *a = new Dog();

	a->set_idea(0, "I want to eat");
	a->set_idea(1, "I want to poop");
	a->set_idea(2, "I want to go out");
	a->set_idea(3, "I want to sleep");

	Dog *b = new Dog(*a);
	delete(b);
	for (int i = 0; i < 4; i++)
		std::cout	<< b->get_idea(i) << std::endl;
	return (0);
}