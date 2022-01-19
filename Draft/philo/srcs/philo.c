/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:34:01 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/19 21:33:05 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eats(t_phil *phil, t_glob *g)
{
	pthread_mutex_lock(&g->forks[phil->l_fork]);
	print_status("has taken a fork\n", phil->id, g);
	pthread_mutex_lock(&g->forks[phil->r_fork]);
	print_status("has taken a fork\n", phil->id, g);
	//pthread_mutex_lock(&g->check);
	print_status("is eating\n", phil->id, g);
	phil->t_last_meal = timestamp();
	//pthread_mutex_unlock(&g->check);
	ft_sleep(g->t_eat, g);
	phil->nb_ate++;
	pthread_mutex_unlock(&g->forks[phil->l_fork]);
	pthread_mutex_unlock(&g->forks[phil->r_fork]);
}

static void	*routine(void *arg)
{
	t_phil	*phil;
	t_glob	*g;

	phil = (t_phil *)arg;
	g = phil->g;
	if (phil->id % 2)
		usleep(15000);
	while (!g->died)
	{
		philo_eats(phil, g);
		if (g->ate_max)
			break ;
		print_status("is sleeping\n", phil->id, g);
		ft_sleep(g->t_sleep, g);
		print_status("is thinking\n", phil->id, g);
	}
	return (NULL);
}

static void	join_destroy(t_glob *g, t_phil *p)
{
	int	i;

	i = 0;
	while (i < g->nb_phil)
	{
		pthread_join(p[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < g->nb_phil)
	{
		pthread_mutex_destroy(&g->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&g->writing);
	return ;
}

static void	check_if_dead(t_glob *g, t_phil *p)
{
	int	i;

	while (!g->ate_max)
	{
		i = 0;
		while (i < g->nb_phil && !(g->died))
		{
			//pthread_mutex_lock(&g->check);
			if (time_diff(p[i].t_last_meal, timestamp()) >= g->t_die)
			{
				print_status("died\n", i, g);
				g->died = 1;
			}
			//pthread_mutex_unlock(&g->check);
			i++;
		}
		if (g->died)
			break ;
		i = 0;
		while (g->nb_max_eat != -1 && i < g->nb_phil
			&& p[i].nb_ate == g->nb_max_eat)
			i++;
		if (i == g->nb_phil)
			g->ate_max = 1;
	}
	return ;
}

int	philo(t_glob *g)
{
	int		i;
	t_phil	*phil;

	i = 0;
	phil = g->phil;
	g->first_timestamp = timestamp();
	while (i < g->nb_phil)
	{
		if (pthread_create(&phil[i].thread_id, NULL, routine, phil + i))
			return (19);
		phil[i].t_last_meal = timestamp();
		i++;
	}
	check_if_dead(g, g->phil);
	join_destroy(g, phil);
	return (0);
}
