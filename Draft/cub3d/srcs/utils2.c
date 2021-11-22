/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:02:28 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/26 17:02:55 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_atoi(const char *input, size_t *i)
{
	unsigned int	ans;
	int				len;

	ans = 0;
	len = 0;
	while (is_space(input[*i]))
		(*i)++;
	if (input[*i] < '0' || input[*i] > '9')
		return (-1);
	while (input[*i] >= '0' && input[*i] <= '9' && ++len)
		ans = (ans * 10) + (input[(*i)++] - '0');
	if (ans > INT_MAX || len > 10)
		return (-1);
	while (is_space(input[*i]))
		(*i)++;
	return (ans);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}
