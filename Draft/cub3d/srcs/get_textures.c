/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:21:28 by lmajerus          #+#    #+#             */
/*   Updated: 2021/04/23 15:33:04 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_end_of_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (!is_space(str[i++]))
			return (19);
	return (0);
}

void	get_textures(char *line, char **ptr_from_map, t_map_info *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*ptr_from_map)
		ft_error("There is a problem in your .cub file, 2x same info", map);
	while (is_space(line[i]))
		i++;
	j = i;
	while (!is_space(line[j]) && line[j])
		j++;
	if (check_end_of_line(line + j))
		ft_error("Text after texture info", map);
	line[j] = '\0';
	*ptr_from_map = malloc(j - i + 1);
	if (*ptr_from_map == NULL)
		ft_error("malloc error", map);
	j = 0;
	while (line[i])
		ptr_from_map[0][j++] = line[i++];
	ptr_from_map[0][j] = '\0';
	map->n++;
}
