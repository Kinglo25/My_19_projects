/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:51:56 by lmajerus          #+#    #+#             */
/*   Updated: 2022/02/02 16:20:23 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_sleep(int time, t_glob *g)
{
	long long	t;

	t = timestamp();
	(void)g;
	while (time_diff(t, timestamp()) <= time)
		usleep(50);
}

int	error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (42);
}

int	mutex_destroy(t_glob *g)
{
	int	i;

	i = 0;
	while (i < g->nb_phil)
	{
		if (pthread_mutex_destroy(&g->forks[i]))
			return (42);
		i++;
	}
	if (pthread_mutex_destroy(&g->check))
		return (42);
	if (pthread_mutex_destroy(&g->writing))
		return (42);
	return (0);
}
