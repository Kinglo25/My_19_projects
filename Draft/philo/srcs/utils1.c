/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:51:56 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/21 13:32:08 by lmajerus         ###   ########.fr       */
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
	while (!g->died && time_diff(t, timestamp()) <= time)
		usleep(50);
}

int	error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (19);
}
