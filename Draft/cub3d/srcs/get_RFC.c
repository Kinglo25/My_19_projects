/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_RFC.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:21:43 by lmajerus          #+#    #+#             */
/*   Updated: 2021/04/22 17:50:40 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_format_R(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && str[i] < '0' && str[i] > '9')
			return (19);
		i++;
	}
}

void	get_RFC(char *line, int int_from_map, t_map_info *map)
{
	size_t	i;

	i = 0;
	while(is_space(line[i]))
		i++;
	if (check_format_R(line + i)
		ft_error("There is a problem in your .cub file", map);
	map->R.x = ft_atoi(line + i, *i)
	while(is_space(line[i]))
		i++;
	map->R.y = ft_atoi(line + i, *i)
	
}
