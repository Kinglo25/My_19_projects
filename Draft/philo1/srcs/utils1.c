/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:35:23 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/24 20:30:07 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *str, t_glob *g, int id)
{
	pthread_mutex_lock(&g->writing);
	if (!g->died)
	{
		printf("%ll ", time_diff(timestamp(), g->start_time));
		printf("%i ", id);
		printf("%s", str);
	}
	pthread_mutex_unlock(&g->writing);
	return ;
}

void	ft_usleep(t_glob *g, int time)
{
	while (!g->died)
	{
		if (time < 0)
			break ;
		usleep(50)
		time -= 50;
	}
	return ;
}
