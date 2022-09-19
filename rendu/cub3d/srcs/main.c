/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:42:11 by lmajerus          #+#    #+#             */
/*   Updated: 2021/11/22 13:44:40 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_argv(int argc, char *argv[])
{
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		printf("Error\nThe name of the map must end by: .cub\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_map_info	map;

	ft_memset(&map, 0, sizeof(map));
	if (argc == 2)
	{
		map.fd = open(argv[1], O_DIRECTORY);
		if (map.fd != -1)
			ft_error("Invalide : is a directory", &map);
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
		mlx(&map);
	}
	else
		write(2, "Error\nInvalid number of arguments.\n", 35);
}
