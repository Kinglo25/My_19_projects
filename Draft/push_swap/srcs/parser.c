/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:53:34 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/05 17:13:03 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_stack a)
{
	long	ans;
	int		i;
	int		signe;

	ans = 0;
	i = 0;
	signe = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			exit(a);
		ans *= 10;
		ans += (int)(str[i] - 48);
		i++;
	}
	ans *= signe;
	if (ans > 2147483647 || ans < -2147483648)
		exit(a);
	return (ans);
}

int	main(int ar, char **av)
{
	return (0);
}
