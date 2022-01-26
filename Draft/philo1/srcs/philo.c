/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:35:16 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/24 20:54:43 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo philo, t_glob *g)
{
	pthread_mutex_lock(&g->forks[philo->l_fork]);
	print_status("has taken a fork\n", g, philo->id);
	if (phil->l_fork == phil->r_fork)
		return ;
	pthread_mutex_lock(&g->forks[philo->f_fork]);
	print_status("has taken a fork\n", g, philo->id);
	pthread_mutex_lock(&g->check);
	print_status("is eating\n");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&g->check);
	ft_usleep(g, g->t_eat);
	philo->nb_ate++;
	pthread_mutex_unlock(&g->forks[philo->l_fork]);
	pthread_mutex_unlock(&g->forks[philo->r_fork]);
}

static void	*routine(void *p)
{
	t_philo	*philo;
	t_glob	*g;

	philo = (t_philo *)p;
	g = philo->g;
	if (philo->id % 2)
		usleep(15000);
	while (!g->died)
	{
		philo_eat(philo, g);
		if (g->done || phil->l_fork == phil->r_fork)
			break ;
		print_status("is sleeping\n", g, philo->id);
		ft_usleep(g, g->t_sleep);
		print_status("is thinking\n", g, philo->id);
	}
	return (NULL);
}

static void	check_if_dead(t_glob *g, t_philo *p, int i)
{
	while (!g->done)
	{
		
	}
}

int	philo(t_glob *g)
{
	size_t	i;

	i = 0;
	g->start_time = timestamp();
	while (i < g->nb_philo)
	{
		if (pthread_create(&g->phil[i].thread_id, NULL, routine, g->phil[i]))
			return (19);
		
		i++;
	}
	check_if_dead(g, g->phil, i);
	join_destroy(g, phil);
	return (0);
}
