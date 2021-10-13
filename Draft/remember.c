/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remember.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:51:53 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/13 15:20:03 by lmajerus         ###   ########.fr       */
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
