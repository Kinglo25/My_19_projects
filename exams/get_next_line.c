/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:21:25 by lmajerus          #+#    #+#             */
/*   Updated: 2021/05/07 16:42:00 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(char **line)
{
	int		i, r, l;
	char	c;
	char	*tmp;

	l = 1;
	if (!(*line = malloc(l)))
		return (-1);
	(*line)[0] = '\0';
	while ((r = read(0, &c, 1)) && l++ && c != '\n')
	{
		if (r == -1 || (!(tmp = malloc(l))))
		{
			free(*line);
			return (-1);
		}
		i = 0;
		while ((*line)[i])
		{
			tmp[i] = (*line)[i];
			i++;
		}
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(*line);
		*line = tmp;
	}
	return (r);
}