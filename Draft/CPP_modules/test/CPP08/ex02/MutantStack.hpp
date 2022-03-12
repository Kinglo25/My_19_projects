/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:09:16 by jandre            #+#    #+#             */
/*   Updated: 2022/02/01 13:44:15 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public :
        typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin(void) 
        {
            return (this->std::stack<T>::c.begin());
        };
		const_iterator begin(void) const 
        {
            return (this->std::stack<T>::c.begin());
        };
		iterator end(void) 
        {
            return (this->std::stack<T>::c.end());
        };
		const_iterator end(void) const 
        {
            return (this->std::stack<T>::c.end());
        };
};

#endif