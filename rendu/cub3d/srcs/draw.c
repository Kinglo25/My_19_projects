/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:50:47 by lmajerus          #+#    #+#             */
/*   Updated: 2021/11/22 15:27:15 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_ceil_floor(t_data *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->m->r.y / 2)
	{
		j = 0;
		while (j < c->m->r.x)
		{
			my_mlx_pixel_put(c, j, i, c->m->c);
			j++;
		}
		i++;
	}
	while (i < c->m->r.y)
	{
		j = 0;
		while (j < c->m->r.x)
		{
			my_mlx_pixel_put(c, j, i, c->m->f);
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *c, int x)
{
	int	y;

	y = c->draw_s;
	while (y < c->draw_e)
	{
		c->tex_y = (int)c->text_pos & (TEXTHEIGHT - 1);
		c->text_pos += c->step;
		c->color = c->text[c->text_num][TEXTHEIGHT
			* c->tex_y + c->tex_x];
		my_mlx_pixel_put(c, x, y, c->color);
		y++;
	}
}
