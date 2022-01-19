/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:26:56 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/19 20:51:44 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_glob	g;

	if (ac != 5 && ac != 6)
		return (error("Invalid # of arg"));
	if (init_all(av, &g))
		return (error("Parsing or initializing issue"));
	if (philo(&g))
		return (error("Could not create threads"));
	return (0);
}
