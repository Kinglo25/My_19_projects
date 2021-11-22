/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:00:39 by lmajerus          #+#    #+#             */
/*   Updated: 2021/11/22 15:26:32 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	perform_dda(t_data *c)
{
	c->hit = 0;
	while (c->hit == 0)
	{
		if (c->sdx < c->sdy)
		{
			c->sdx += c->ddx;
			c->map_x += c->step_x;
			c->side = 0;
		}
		else
		{
			c->sdy += c->ddy;
			c->map_y += c->step_y;
			c->side = 1;
		}
		if (c->m->map[c->map_x][c->map_y] == '1')
			c->hit = 1;
	}
	if (c->side == 0)
		c->pwd = c->sdx - c->ddx;
	else
		c->pwd = c->sdy - c->ddy;
}

void	calc_sd(t_data *c)
{
	if (c->rdx < 0)
	{
		c->step_x = -1;
		c->sdx = (c->m->pos_x - c->map_x) * c->ddx;
	}
	else
	{
		c->step_x = 1;
		c->sdx = (c->map_x + 1.0 - c->m->pos_x) * c->ddx;
	}
	if (c->rdy < 0)
	{
		c->step_y = -1;
		c->sdy = (c->m->pos_y - c->map_y) * c->ddy;
	}
	else
	{
		c->step_y = 1;
		c->sdy = (c->map_y + 1.0 - c->m->pos_y) * c->ddy;
	}
}

void	init_vars(t_data *c, int x)
{
	c->cam_x = 2 * x / (double)c->m->r.x - 1;
	c->rdx = c->m->dx + c->m->px * c->cam_x;
	c->rdy = c->m->dy + c->m->py * c->cam_x;
	c->map_x = (int)c->m->pos_x;
	c->map_y = (int)c->m->pos_y;
	c->ddx = fabs(1 / c->rdx);
	c->ddy = fabs(1 / c->rdy);
	calc_sd(c);
	perform_dda(c);
	c->line_h = (int)(c->m->r.y / c->pwd);
	c->draw_s = -c->line_h / 2 + c->m->r.y / 2;
	if (c->draw_s < 0)
		c->draw_s = 0;
	c->draw_e = c->line_h / 2 + c->m->r.y / 2;
	if (c->draw_s >= c->m->r.y || c->draw_e < 0)
		c->draw_s = c->m->r.y - 1;
	if (c->side == 1 && c->rdx > 0)
		c->text_num = 0;
	if (c->side == 1 && c->rdx <= 0)
		c->text_num = 1;
	if (c->side == 0 && c->rdy > 0)
		c->text_num = 2;
	if (c->side == 0 && c->rdy <= 0)
		c->text_num = 3;
}

void	set_text_vars(t_data *c)
{
	if (c->side == 0)
		c->wall_x = c->m->pos_y + c->pwd * c->rdy;
	else
		c->wall_x = c->m->pos_x + c->pwd * c->rdx;
	c->wall_x -= floor(c->wall_x);
	c->tex_x = (int)(c->wall_x * (double)TEXTWIDTH);
	if (c->side == 0 && c->rdx > 0)
		c->tex_x = TEXTWIDTH - c->tex_x - 1;
	if (c->side == 1 && c->rdy < 0)
		c->tex_x = TEXTWIDTH - c->tex_x - 1;
	c->step = 1.0 * TEXTWIDTH / c->line_h;
	c->text_pos = (c->draw_s - c->m->r.y / 2 + c->line_h / 2) * c->step;
}

int	raycasting(t_data *c)
{
	int	x;

	x = 0;
	draw_ceil_floor(c);
	while (x < c->m->r.x)
	{
		init_vars(c, x);
		set_text_vars(c);
		draw_line(c, x);
		x++;
	}
	mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0);
	return (0);
}
