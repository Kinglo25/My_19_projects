/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:22:25 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/05 14:55:33 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_n_len(unsigned int x)
{
	if (x < 10u)
		return (1);
	return (1 + find_n_len(x / 10));
}

char	*ft_itoa(int n)
{
	char			*ans;
	int				n_len;
	unsigned int	x;

	x = (n < 0) ? -n : n;
	n_len = find_n_len(x);
	if (n < 0)
		n_len++;
	if (!(ans = malloc(n_len + 1)))
		return (NULL);
	ans[n_len--] = '\0';
	if (n < 0)
		ans[0] = '-';
	if (x == 0)
		ans[0] = '0';
	while (x)
	{
		ans[n_len--] = (char)(x % 10 + 48);
		x /= 10;
	}
	return (ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remember.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:51:53 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/05 13:39:19 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	find_len_n(unsigned int x)
{
	if (x < 10u)
		return (1);
	return (1 + find_len_n(x / 10));
}

char	*ft_itoa(int n)
{
	unsigned int	x;
	char			*ans;
	int				len;

	if (n < 0)
		x = -n;
	else
		x = n;
	len = find_len_n(x);
	if (n < 0)
		len++;
	ans = malloc(len * sizeof(char) + 1);
	if (!ans)
		return (NULL);
	ans[len--] = '\0';
	if (x == 0)
		ans[0] = '0';
	while (x)
	{
		ans[len--] = x % 10 + 48;
		x /= 10;
	}
	if (n < 0)
		ans[0] = '-';
	return (ans);
}
