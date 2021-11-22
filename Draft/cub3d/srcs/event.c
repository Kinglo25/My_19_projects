/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:45:43 by lmajerus          #+#    #+#             */
/*   Updated: 2021/11/02 18:30:36 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_struct(t_map_info *map)
{
	int	i;

	i = 0;
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
}

int	ft_exit(t_data *c, int ret)
{
	printf("cleaning memory...\n");
	free_struct(c->m);
	if (c->img)
		mlx_destroy_image(c->mlx, c->img);
	if (c->wall_n)
		mlx_destroy_image(c->mlx, c->wall_n);
	if (c->wall_e)
		mlx_destroy_image(c->mlx, c->wall_e);
	if (c->wall_s)
		mlx_destroy_image(c->mlx, c->wall_s);
	if (c->wall_w)
		mlx_destroy_image(c->mlx, c->wall_w);
	if (c->win)
		mlx_clear_window(c->mlx, c->win);
	if (c->win)
		mlx_destroy_window(c->mlx, c->win);
	printf("Memory cleaned.\n");
	exit(ret);
	return (ret);
}

int	ft_exit_button(t_data *c)
{
	return (ft_exit(c, 0));
}

int	key_hook(int key, t_data *c)
{
	if (key == ESC)
		ft_exit(c, 0);
	else if (key == W || key == S)
		move_updown(key, c);
	else if (key == A || key == D)
		move_leftright(key, c);
	else if (key == RIGHT || key == LEFT)
		turn_leftright(key, c);
	return (1);
}
