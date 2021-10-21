/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:09:33 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/20 17:10:52 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_error(char *strerror, t_map_info *map)
{
	int	i;

	i = 0;
	printf("Error\n%s\n", strerror);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->s)
		free(map->s);
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
	exit(0);
}

void	put_in_struct_2(char *line, t_map_info *map)
{
	size_t	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (map->n != 8 && line[i] == '1')
		ft_error("There is a problem in your .cub file", map);
	else if (map->n == 8 && line[i] == '1')
		get_map(line, map);
	else if (!is_space(line[i]))
		ft_error("wrong char in your .cub file", map);
}

void	put_in_struct(char *line, t_map_info *map)
{
	size_t	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->no, map);
	else if (line[i] == 'S' && line[i + 1] == 'O' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->so, map);
	else if (line[i] == 'E' && line[i + 1] == 'A' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->ea, map);
	else if (line[i] == 'W' && line[i + 1] == 'E' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->we, map);
	else if (line[i] == 'S' && is_space(line[i + 1]))
		get_textures(line + i + 1, &map->s, map);
	else if (line[i] == 'R' && is_space(line[i + 1]))
		get_resolution(line + i + 1, map);
	else if (line[i] == 'F' && is_space(line[i + 1]))
		get_floor_ceiling(line + i + 1, &map->f, map);
	else if (line[i] == 'C' && is_space(line[i + 1]))
		get_floor_ceiling(line + i + 1, &map->c, map);
	else if (line[i] == '\0')
		return ;
	else
		put_in_struct_2(line, map);
}

void	parser(t_map_info *map)
{
	char	*line;
	int		gnl_return;

	while (1)
	{
		gnl_return = get_next_line(map->fd, &line);
		if (gnl_return == -1)
			ft_error("There was an error with gnl", map);
		put_in_struct(line, map);
		free(line);
		if (gnl_return == 0)
			break ;
	}
	close(map->fd);
}
