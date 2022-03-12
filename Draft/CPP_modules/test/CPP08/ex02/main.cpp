/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:43:08 by jandre            #+#    #+#             */
/*   Updated: 2022/02/01 13:56:55 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "Trying Mutated Class : " << std::endl;
        MutantStack<int> mstack;
        std::cout << std::endl << "Adding 5, 17 at the end of the stack and printing last element" << std::endl;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        std::cout << std::endl << "Removing last element and printing the size" << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        std::cout << std::endl << "Adding 3, 5, 737, 0 at the end of the stack" << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        std::cout << std::endl << "Trying the iterators of the class and printing the stack" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "Trying List Container : " << std::endl;
        std::list<int> mstack;
        std::cout << std::endl << "Adding 5, 17 at the end of the stack and printing last element" << std::endl;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        std::cout << std::endl << "Removing last element and printing the size" << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        std::cout << std::endl << "Adding 3, 5, 737, 0 at the end of the stack" << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::cout << std::endl << "Trying the iterators of the containers and printing the stack" << std::endl;
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(mstack);
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "Trying vector Container : " << std::endl;
        std::vector<int> mstack;
        std::cout << std::endl << "Adding 5, 17 at the end of the stack and printing last element" << std::endl;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        std::cout << std::endl << "Removing last element and printing the size" << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        std::cout << std::endl << "Adding 3, 5, 737, 0 at the end of the stack" << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::cout << std::endl << "Trying the iterators of the containers and printing the stack" << std::endl;
        std::vector<int>::iterator it = mstack.begin();
        std::vector<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::vector<int> s(mstack);
    }
    return 0;
}