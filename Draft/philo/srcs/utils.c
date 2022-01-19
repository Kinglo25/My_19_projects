/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:52:07 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/19 18:03:56 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int						i;
	int						signe;
	unsigned long long int	ans;
	int						nb_len;

	signe = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (-1);
	ans = 0;
	nb_len = 0;
	while (*str)
	{
		if (str[i] >= '0' && str[i] <= '9')
			ans = (ans * 10) + (str[i++] - '0');
		else
			return (-1);
	}
	return ((int)ans * signe);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	print_status(char *str, int id, t_global *g)
{
	pthread_mutex_lock(&g->writing);
	if (!g->died)
	{
		printf("%lli ", timestamp() - g->first_timestamp);
		printf("%i ", id + 1);
		write(1, str, ft_strlen(str));
	}
	pthread_mutex_unlock(&(g->writing));
	return ;
}
