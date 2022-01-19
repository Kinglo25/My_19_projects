/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:51:29 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/19 20:05:13 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_glob *g)
{
	int	i;

	i = 0;
	while (i < g->nb_phil)
	{
		if (pthtread_mutex_init(g->forks + i, NULL))
			return (19);
		i++;
	}
	if (pthtread_mutex_init(&g->check, NULL))
		return (19);
	if (pthtread_mutex_init(&g->writing, NULL))
		return (19);
	return (0);
}

static void	init_philosophers(t_glob *g)
{
	int	i;

	i = 0;
	while (i < g->nb_phil)
	{
		g->phil[i].id = i;
		g->phil[i].nb_ate = 0;
		g->phil[i].l_fork = i;
		g->phil[i].r_fork = (i + 1) % g->nb_phil;
		g->phil[i].t_last_meal = 0;
		g->phil[i].g = g;
	}
}

int	init_all(int ac, char **av, t_glob *g)
{
	g->nb_phil = ft_atoi(av[1]);
	g->t_die = ft_atoi(av[2]);
	g->t_eat = ft_atoi(av[3]);
	g->t_sleep = ft_atoi(av[4]);
	g->ate_max = 0;
	g->died = 0;
	if (g->nb_phil < 2 || g->nb_phil > 200 || g->t_die < 60
		|| g->t_eat < 60 || g->t_sleep < 60)
		return (19);
	if (av[5])
	{
		g->nb_max_eat = ft_atoi(av[5]);
		if (g->nb_max_eat <= 0)
			return (19);
	}
	else
		g->nb_max_eat = -1;
	if (init_mutex(g))
		return (42);
	init_philosophers(g);
	return (0);
}
