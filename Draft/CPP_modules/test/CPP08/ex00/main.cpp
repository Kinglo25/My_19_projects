/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:37:11 by jandre            #+#    #+#             */
/*   Updated: 2022/01/27 21:07:03 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#define SIZE 50

template <typename T>
void try_find(T &data, int toFind)
{
    try
    {
        easyfind(data, toFind);
        std::cout << toFind << " found" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << toFind << " not found" <<std::endl;
    }
    return ;
}

int main()
{
    //vector container
    {
        std::vector<int> vect;
        for (int i = 0; i < SIZE; i++)
            vect.push_back(i);
        std::cout << "Test vector :" << std::endl << "( ";
        for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
            std::cout << *it << " ";
        std::cout << ")" << std::endl;
        try_find(vect, 2);
        try_find(vect, 10);
        try_find(vect, 123);
        try_find(vect, 3);
        try_find(vect, 43);
        try_find(vect, 5);
        try_find(vect, 7);
        try_find(vect, 0);
        try_find(vect, 1);
        try_find(vect, -23);

        //testing empty vector
        vect.clear();
        try_find(vect, 3);
    }
    //list container
    {
        std::list<int> lst;
        for (int i = 0; i < SIZE; i++)
            lst.push_back(i);
        std::cout << "Test list :" << std::endl << "( ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << " ";
        std::cout << ")" << std::endl;
        try_find(lst, 2);
        try_find(lst, 10);
        try_find(lst, 123);
        try_find(lst, 3);
        try_find(lst, 43);
        try_find(lst, 5);
        try_find(lst, 7);
        try_find(lst, 0);
        try_find(lst, 1);
        try_find(lst, -23);

        //testing empty list
        lst.clear();
        try_find(lst, 3);
    }

    return (0);
}