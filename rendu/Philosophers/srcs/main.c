/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:26:56 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/27 16:20:08 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_glob	g;

	if (ac != 5 && ac != 6)
		return (error("Invalid # of arg", &g));
	if (init_all(av, &g))
		return (error("Parsing or init issue", &g) && !mutex_destroy(&g));
	if (philo(&g))
		return (error("Couldn't create threads", &g) && !mutex_destroy(&g));
	return (0);
}
