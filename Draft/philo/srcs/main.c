/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:35:12 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/24 17:20:06 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_glob	g;

	if (ac != 5 && ac != 6)
		return (error("Error : invalid # of arg.\n"));
	if (init_all(&g, av))
		return (error("Error : Initializing or parsing issue.\n"));
}
