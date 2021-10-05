/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:12:27 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/05 11:28:13 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			signe *= -1;
	ans = 0;
	nb_len = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i++] - '0');
		if (ans > 9223372036854775807 || ++nb_len > 19)
		{
			if (signe == 1)
				return (-1);
			return (0);
		}
	}
	return (ans * signe);
}
