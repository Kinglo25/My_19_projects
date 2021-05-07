/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:03:34 by lmajerus          #+#    #+#             */
/*   Updated: 2021/05/07 16:07:36 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	tab[255] = {0};
	int	i = 0;

	if (argc == 3)
	{
		while(argv[1][i])
		{
			if (!tab[(unsigned int)argv[1][i]]++)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while(argv[2][i])
		{
			if (!tab[(unsigned int)argv[2][i]]++)
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}