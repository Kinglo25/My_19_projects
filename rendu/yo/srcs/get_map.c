/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:48:03 by lmajerus          #+#    #+#             */
/*   Updated: 2021/12/09 13:50:40 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	get_pos_and_dir(t_map_info *map, int i, int j, char c)
{
	map->pos_x = i + 0.5;
	map->pos_y = j + 0.5;
	if (c == 'N')
	{
		map->dy = -1;
		map->px = 0.66;
	}
	if (c == 'S')
	{
		map->dy = 1;
		map->px = -0.66;
	}
	if (c == 'W')
	{
		map->dx = -1;
		map->py = -0.66;
	}
	if (c == 'E')
	{
		map->dx = 1;
		map->py = 0.66;
	}
	map->map[i][j] = '0';
}

static int	check_char(char c, t_map_info *map, int i, int j)
{
	if ((c == 'W' || c == 'S' || c == 'N' || c == 'E') && map->error++)
		return (19);
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
		get_pos_and_dir(map, i, j, c);
	return (c != '1' && c != '0' && c != 'W'
		&& c != 'S' && c != 'N' && c != 'E' && !is_space(c));
}

static void	check_map(t_map_info *map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		len = ft_strlen(map->map[i]);
		while (map->map[i][j])
		{
			if ((i == 0 || j == 0 || i == (map->map_len - 1) || j == (len - 1))
				&& (map->map[i][j] != '1' && !is_space(map->map[i][j])))
				ft_error("Please check your map!", map);
			if (check_char(map->map[i][j], map, i, j))
				ft_error("Wrong char in your map", map);
			if (map->map[i][j] != '1' && !is_space(map->map[i][j]))
				if (is_space(map->map[i - 1][j]) || is_space(map->map[i][j - 1])
				|| is_space(map->map[i + 1][j]) || is_space(map->map[i][j + 1]))
					ft_error("Your map is not closed", map);
			j++;
		}
		i++;
	}
}

void	get_map(char *line, t_map_info *map)
{
	static size_t	y;
	size_t			i;

	i = 0;
	if (!map->map)
		map->map = malloc(map->map_len * sizeof(char *) + 1);
	if (map->map == NULL)
		ft_error("malloc error", map);
	map->map[map->map_len] = NULL;
	map->map[y] = malloc(ft_strlen(line) + 1);
	if (map->map[y] == NULL)
		ft_error("malloc error", map);
	while (line[i])
	{
		map->map[y][i] = line[i];
		i++;
	}
	map->map[y][i] = '\0';
	y++;
	if (y == map->map_len)
	{
		check_map(map);
		if (map->error != 1)
			ft_error("Missing or multiple player position", map);
	}
}

void	get_map_len(char *str, t_map_info *map)
{
	size_t	i;
	char	*line;
	int		gnl_return;

	map->fd = open(str, O_RDONLY);
	if (map->fd == -1)
	{
		printf("Error\nCan not open the *.cub file\n");
		exit(0);
	}
	while (1)
	{
		i = 0;
		gnl_return = get_next_line(map->fd, &line);
		if (gnl_return == -1)
			ft_error("There was an error with gnl", map);
		while (is_space(line[i]))
			i++;
		if (line[i] == '1')
			++map->map_len;
		free(line);
		if (gnl_return == 0)
			break ;
	}
	close(map->fd);
}
