/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:35:20 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/24 19:59:02 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error(char *str)
{
	write (1, str, ft_strlen(str));
	return (19);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		ans;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ans = ans * 10 + ((int)str[i] - 48);
		else
			return (-1);
		i++;
	}
	return (ans);
}

long long	time_diff(long long pres, long long past)
{
	return (pres - past);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
