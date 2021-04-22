/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:09:33 by lmajerus          #+#    #+#             */
/*   Updated: 2021/04/22 17:47:03 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_error(char *strerror, t_map_info *map)
{
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
	exit(0);
}

void	put_in_struct(char *line, t_map_info *map)
{
	size_t	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_textures(line + i + 2, map->NO, map);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_textures(line + i + 2, map->SO, map);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		get_textures(line + i + 2, map->EA, map);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		get_textures(line + i + 2, map->WE, map);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		get_textures(line + i + 1, map->S, map);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		get_RFC(line + i + 1, map->R, map);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		get_RFC(line + i + 1, map->F, map);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		get_RFC(line + i + 1, map->C, map);
}

static void	check_argv(int argc, char *argv[])
{
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
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

	while (1)
	{
		if (get_next_line(map->fd, &line) == -1)
			ft_error("There was an error with gnl", map);
		put_in_struct(line, map);
	}
}

int	main(int argc, char *argv[])
{
	t_map_info	map;

	ft_memset(&map, 0, sizeof(map));
	if (argc == 2 || argc == 3)
	{
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
