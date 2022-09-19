/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:55:29 by lmajerus          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:42 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_updown(int key, t_data *c)
{
	if (key == W)
	{
		if (c->m->map[(int)(c->m->pos_x + c->m->dy * MS)]
			[(int)c->m->pos_y] == '0')
			c->m->pos_x += c->m->dy * MS;
		if (c->m->map[(int)c->m->pos_x]
			[(int)(c->m->pos_y + c->m->dx * MS)] == '0')
			c->m->pos_y += c->m->dx * MS;
	}
	if (key == S)
	{
		if (c->m->map[(int)(c->m->pos_x - c->m->dy * MS)]
			[(int)c->m->pos_y] == '0')
			c->m->pos_x -= c->m->dy * MS;
		if (c->m->map[(int)c->m->pos_x]
			[(int)(c->m->pos_y - c->m->dx * MS)] == '0')
			c->m->pos_y -= c->m->dx * MS;
	}
}

void	move_leftright(int key, t_data *c)
{
	if (key == D)
	{
		if (c->m->map[(int)(c->m->pos_x + c->m->py * MS)]
			[(int)c->m->pos_y] == '0')
			c->m->pos_x += c->m->py * MS;
		if (c->m->map[(int)c->m->pos_x]
			[(int)(c->m->pos_y + c->m->px * MS)] == '0')
			c->m->pos_y += c->m->px * MS;
	}
	if (key == A)
	{
		if (c->m->map[(int)(c->m->pos_x - c->m->py * MS)]
			[(int)c->m->pos_y] == '0')
			c->m->pos_x -= c->m->py * MS;
		if (c->m->map[(int)c->m->pos_x]
			[(int)(c->m->pos_y - c->m->px * MS)] == '0')
			c->m->pos_y -= c->m->px * MS;
	}
}

void	turn_leftright(int key, t_data *c)
{
	if (key == LEFT)
	{
		c->o_dx = c->m->dx;
		c->m->dx = c->m->dx * cos(-TSP) - c->m->dy * sin(-TSP);
		c->m->dy = c->o_dx * sin(-TSP) + c->m->dy * cos(-TSP);
		c->o_px = c->m->px;
		c->m->px = c->m->px * cos(-TSP) - c->m->py * sin(-TSP);
		c->m->py = c->o_px * sin(-TSP) + c->m->py * cos(-TSP);
	}
	if (key == RIGHT)
	{
		c->o_dx = c->m->dx;
		c->m->dx = c->m->dx * cos(TSP) - c->m->dy * sin(TSP);
		c->m->dy = c->o_dx * sin(TSP) + c->m->dy * cos(TSP);
		c->o_px = c->m->px;
		c->m->px = c->m->px * cos(TSP) - c->m->py * sin(TSP);
		c->m->py = c->o_px * sin(TSP) + c->m->py * cos(TSP);
	}
}
