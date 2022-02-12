/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:34:01 by lmajerus          #+#    #+#             */
/*   Updated: 2022/02/02 16:27:30 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eats(t_phil *phil, t_glob *g)
{
	if (pthread_mutex_lock(&g->forks[phil->l_fork]))
		return (42);
	if (print_status("has taken a fork\n", phil->id, g))
		return (42);
	if (phil->l_fork == phil->r_fork)
		return (pthread_mutex_unlock(&g->forks[phil->l_fork]));
	if (pthread_mutex_lock(&g->forks[phil->r_fork]))
		return (42);
	if (print_status("has taken a fork\n", phil->id, g))
		return (42);
	if (pthread_mutex_lock(&g->check))
		return (42);
	phil->t_last_meal = timestamp();
	if (print_status("is eating\n", phil->id, g))
		return (42);
	if (pthread_mutex_unlock(&g->check))
		return (42);
	ft_sleep(g->t_eat, g);
	phil->nb_ate++;
	if (pthread_mutex_unlock(&g->forks[phil->l_fork]))
		return (42);
	if (pthread_mutex_unlock(&g->forks[phil->r_fork]))
		return (42);
	usleep(100);
	return (0);
}

static void	*routine(void *arg)
{
	t_phil	*phil;
	t_glob	*g;

	phil = (t_phil *)arg;
	g = phil->g;
	if (phil->id % 2)
		usleep(15000);
	while (!g->died && !g->ate_max)
	{
		philo_eats(phil, g);
		if (phil->l_fork == phil->r_fork)
			break ;
		print_status("is sleeping\n", phil->id, g);
		ft_sleep(g->t_sleep, g);
		print_status("is thinking\n", phil->id, g);
		usleep(500);
	}
	return (NULL);
}

static int	check_if_dead(t_glob *g, t_phil *p, int i)
{
	while (!g->ate_max)
	{
		i = 0;
		while (i < g->nb_phil && !(g->died))
		{
			pthread_mutex_lock(&g->check);
			if (time_diff(p[i].t_last_meal, timestamp()) >= g->t_die)
			{
				if (print_status("died\n", i, g))
					return (42);
				g->died = 1;
			}
			pthread_mutex_unlock(&g->check);
			i++;
		}
		if (g->died)
			break ;
		i = 0;
		while (g->nb_max_eat != -1 && i < g->nb_phil
			&& p[i].nb_ate >= g->nb_max_eat)
			i++;
		if (i == g->nb_phil)
			g->ate_max = 1;
	}
	return (0);
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
			return (42);
		pthread_mutex_lock(&g->check);
		phil[i].t_last_meal = timestamp();
		pthread_mutex_unlock(&g->check);
		usleep(500);
		i++;
	}
	check_if_dead(g, g->phil, i);
	i = 0;
	while (i < g->nb_phil)
		if (pthread_join(phil[i++].thread_id, NULL))
			return (42);
	if (mutex_destroy(g))
		return (42);
	return (0);
}
