/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:35:09 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/24 20:34:18 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_glob *g)
{
	size_t	i;

	i = 0;
	while (i < g->nb_philo)
	{
		if (pthread_mutex_init(&g->forks[i], NULL))
			return (19);
		i++;
	}
	if (pthread_mutex_init(&g->writing, NULL))
		return (19);
	if (pthread_mutex_init(&g->check, NULL))
		return (19);
	return (0);
}

static void	init_philo(t_lob *g)
{
	size_t	i;

	i = 0;
	while (i < g->nb_philo)
	{
		g->phil[i].id = i;
		g->phil[i].l_fork = i;
		g->phil[i].r_fork = (i + 1) % g->nb_philo;
		g->phil[i].nb_ate = 0;
		g->phil[i].t_last_meal = 0;
		g->phil[i].g = g;
	}
	return ;
}

int	init_all(t_glob *g, char *av[])
{
	g->nb_philo = ft_atoi(av[1]);
	g->t_die = ft_atoi(av[2]);
	g->t_eat = ft_atoi(av[3]);
	g->t_sleep = ft_atoi(av[4]);
	g->done = 0;
	g->died = 0;
	g->nb_m_eat = 0;
	if (av[5])
		g->nb_m_eat = ft_atoi(av[5]);
	if (g->nb_philo < 1 || g->t_die < 60 || g->t_eat < 60
		g->t_sleep < 60 || g->nb_m_eat < 0)
		return (19);
	init_philo(g);
	if (init_mutex(g))
		return (19);
	return (0);
}
