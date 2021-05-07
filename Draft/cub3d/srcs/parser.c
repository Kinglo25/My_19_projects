/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:09:33 by lmajerus          #+#    #+#             */
/*   Updated: 2021/05/05 17:48:39 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_error(char *strerror, t_map_info *map)
{
	int	i;

	i = 0;
	printf("Error\n%s\n", strerror);
	if (map->NO)
		free(map->NO);
	if (map->SO)
		free(map->SO);
	if (map->EA)
		free(map->EA);
	if (map->WE)
		free(map->WE);
	if (map->S)
		free(map->S);
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
		get_textures(line + i + 2, &map->NO, map);
	else if (line[i] == 'S' && line[i + 1] == 'O' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->SO, map);
	else if (line[i] == 'E' && line[i + 1] == 'A' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->EA, map);
	else if (line[i] == 'W' && line[i + 1] == 'E' && is_space(line[i + 2]))
		get_textures(line + i + 2, &map->WE, map);
	else if (line[i] == 'S' && is_space(line[i + 1]))
		get_textures(line + i + 1, &map->S, map);
	else if (line[i] == 'R' && is_space(line[i + 1]))
		get_resolution(line + i + 1, map);
	else if (line[i] == 'F' && is_space(line[i + 1]))
		get_floor_ceiling(line + i + 1, &map->F, map);
	else if (line[i] == 'C' && is_space(line[i + 1]))
		get_floor_ceiling(line + i + 1, &map->C, map);
	else if (line[i] == '\0')
		return ;
	else
		put_in_struct_2(line, map);
}

static void	check_argv(int argc, char *argv[])
{
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
	{
		printf("Error\nThe third argument must be: --save\n");
		exit(0);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		printf("Error\nThe name of the map must end by: .cub\n");
		exit(0);
	}
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

int	main(int argc, char *argv[])
{
	t_map_info	map;

	ft_memset(&map, 0, sizeof(map));
	if (argc == 2 || argc == 3)
	{
		get_map_len(argv[1], &map);
		if (map.map_len == 0)
			ft_error("no map", &map);
		check_argv(argc, argv);
		map.fd = open(argv[1], O_RDONLY);
		if (map.fd == -1)
		{
			printf("Error\nCan not open the *.cub file\n");
			exit(0);
		}
		parser(&map);
	}
	else
		write(2, "Error\nInvalid number of arguments.\n", 35);
}
