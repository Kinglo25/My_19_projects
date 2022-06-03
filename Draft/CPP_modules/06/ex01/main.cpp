/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:05:22 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/01 17:58:56 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

typedef struct Data {
    int i;
    char c;
    const char *str;
}               Data;

uintptr_t serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data *data = new Data;
    Data *data2 = NULL;
    uintptr_t i;

    data->i = 42;
    data->c = 'D';
    data->str = "Coucou petite perruche";
    std::cout << "Avant : " << data << ", " << data->c << ", " << data->str << ", " << data->i << std::endl << std::endl;
    i = serialize(data);
    std::cout << "uintptr_t : " << i << std::endl << std::endl;
    data2 = deserialize(i);
    std::cout << "Apres : " << data2 << ", " << data2->c << ", " << data2->str << ", " << data2->i << std::endl;
    delete data;
    return (0);
}