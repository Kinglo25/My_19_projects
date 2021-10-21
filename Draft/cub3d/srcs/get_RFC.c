/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_RFC.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:21:43 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/20 16:43:59 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_format_r(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && str[i] < '0' && str[i] > '9')
			return (19);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (is_space(str[i]))
		i++;
	if (!str[i])
		return (19);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
		if (!is_space(str[i++]))
			return (19);
	return (0);
}

void	get_resolution(char *line, t_map_info *map)
{
	size_t	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (check_format_r(line + i))
		ft_error("There is a problem in your .cub file check R format", map);
	map->r.x = ft_atoi(line, &i);
	while (is_space(line[i]))
		i++;
	map->r.y = ft_atoi(line, &i);
	if (map->r.x == -1 || map->r.y == -1 || map->r.x == 0 || map->r.y == 0)
		ft_error("There is a problem in your .cub file check R format", map);
	while (line[i])
		if (!is_space(line[i++]))
			ft_error("Wrong char in resolution", map);
	map->n++;
}

static int	check_format_fc(char *str, t_map_info *map)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && str[i] < '0' && str[i] > '9' && str[i] == ',')
			return (19);
		i++;
	}
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || is_space(str[i]))
		i++;
	if (str[i] == ',')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || is_space(str[i]))
		i++;
	if (str[i] == ',')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || is_space(str[i]))
		i++;
	while (str[i])
		if (!is_space(str[i++]))
			return (19);
	return (0);
}

static int	check_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (19);
	if (g < 0 || g > 255)
		return (19);
	if (b < 0 || b > 255)
		return (19);
	return (0);
}

void	get_floor_ceiling(char *line, int *int_from_map, t_map_info *map)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (check_format_fc(line + i, map))
		ft_error("There is a problem in your .cub file, check F/C format", map);
	r = ft_atoi(line, &i);
	if (line[i] == ',')
		i++;
	else
		ft_error("There is a problem in your .cub file, check F/C format", map);
	g = ft_atoi(line, &i);
	if (line[i] == ',')
		i++;
	else
		ft_error("There is a problem in your .cub file, check F/C format", map);
	b = ft_atoi(line, &i);
	if (check_rgb(r, g, b))
		ft_error("rgb color must be between 0 and 255", map);
	*int_from_map = create_rgb(r, g, b);
	map->n++;
}
