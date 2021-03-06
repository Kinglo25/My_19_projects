/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:07:59 by lmajerus          #+#    #+#             */
/*   Updated: 2021/05/07 17:07:41 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	tab[255] = {0};
	int	j, i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && !tab[(unsigned int)argv[1][i]]++)
					{
						write(1, &argv[1][i], 1);
						break;
					}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
