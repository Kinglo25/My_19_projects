/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:57:16 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/11 20:29:33 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;
	
	if (ac == 1)
		std::cout << "MEUNIER TU DORS TON MOULIN VA TROP VITE";
	else
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				c = toupper(av[i][j]);
				std::cout << c;
				j++;	
			}
			i++;
		}	
	}
	std::cout << std::endl;
	return (0);
}