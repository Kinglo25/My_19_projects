/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:30:40 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/17 16:36:34 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::left << std::setw(10) << std::setfill('.');
	std::cout << 777777777 << std::endl;
}