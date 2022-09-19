/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:03:54 by lmajerus          #+#    #+#             */
/*   Updated: 2021/11/22 15:37:41 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	get_image(t_data *c)
{
	int	w;
	int	h;
	int	id;

	c->wall_n = mlx_xpm_file_to_image(c->mlx, c->m->no, &w, &h);
	c->wall_s = mlx_xpm_file_to_image(c->mlx, c->m->so, &w, &h);
	c->wall_e = mlx_xpm_file_to_image(c->mlx, c->m->ea, &w, &h);
	c->wall_w = mlx_xpm_file_to_image(c->mlx, c->m->we, &w, &h);
	if (!c->wall_n || !c->wall_s || !c->wall_e || !c->wall_w)
		ft_error("can't open xpm files\n", c->m);
	c->text[0] = (int *)mlx_get_data_addr(c->wall_n, &id, &id, &id);
	c->text[1] = (int *)mlx_get_data_addr(c->wall_s, &id, &id, &id);
	c->text[2] = (int *)mlx_get_data_addr(c->wall_e, &id, &id, &id);
	c->text[3] = (int *)mlx_get_data_addr(c->wall_w, &id, &id, &id);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	mlx(t_map_info *map)
{
	t_data	c;
	int		id;

	ft_memset(&c, 0, sizeof(c));
	c.m = map;
	c.mlx = mlx_init();
	c.win = mlx_new_window(c.mlx, c.m->r.x, c.m->r.y, "Cub3D");
	c.img = mlx_new_image(c.mlx, c.m->r.x, c.m->r.y);
	c.addr = mlx_get_data_addr(c.img, &c.bpp, &c.line_len, &c.endian);
	get_image(&c);
	mlx_hook(c.win, 2, 1L << 0, key_hook, &c);
	mlx_hook(c.win, 17, 0, ft_exit_button, &c);
	mlx_loop_hook(c.mlx, raycasting, &c);
	mlx_loop(c.mlx);
	return (ft_exit(&c, 0));
}
