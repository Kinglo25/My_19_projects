/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:24:05 by lmajerus          #+#    #+#             */
/*   Updated: 2022/02/03 13:50:57 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_drawing
{
	int		width;
	int		height;
	char	background;
	char	*matrice;
}			t_drawing;

typedef struct s_rectangle
{
	char	type;
	float	x;
	float	y;
	float	height;
	float	width;
	char	c;
}			t_rectangle;

int	get_info(FILE *file, t_drawing *draw)
{
	int	i;

	if (fscanf(file, "%d %d %c\n", &draw->width, &draw->height, &draw->background) == 3)
	{
		if (draw->width > 300 || draw->width < 1 || draw->height > 300 || draw->height < 1)
			return (printf("yes\n"));
		draw->matrice = malloc(draw->width * draw->height);
		if (!draw->matrice)
			return (printf("yes\n"));
		i = 0;
		while (i < (draw->width * draw->height))
			draw->matrice[i++] = draw->background;
		return (0);
	}
	return (printf("yesww\n"));
}

int	is_in_rect(t_rectangle *rect, float x, float y)
{
	if (x < rect->x || x > (rect->x + rect->width) || y < rect->y || y > (rect->y + rect->height))
		return (0);
	if ((x - rect->x) < 1.0f || (rect->x + rect->width - x) < 1.0f || (y - rect->y) < 1.0f || (rect->y + rect->height) - y)
		return (2);
	return (1);
}

void	drawing(t_rectangle *rect, t_drawing *draw, int x, int y)
{
	int	ret;
	ret = is_in_rect(rect, (float)x, (float)y);
	if (ret == 2 || (ret == 1 && rect->type == 'R'))
		draw->matrice[x + y * draw->width] = rect->c;
	return ;
}

int	loop(t_rectangle *rect, t_drawing *draw)
{
	int	i;
	int	j;

	if (rect->width < 0.0f || rect->height < 0.0f || (rect->type != 'r' && rect->type != 'R'))
		return (1);
	i = 0;
	while (i < draw->width)
	{
		j = 0;
		while (j < draw->height)
		{
			drawing(rect, draw, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	execute(FILE *file)
{
	t_drawing	draw;
	t_rectangle	rect;
	int			scan_ret;
	int		i;

	if (!get_info(file, &draw))
	{
		while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.c) == 6))
			if (loop(&rect, &draw))
				return (printf("yes\n"));
		if (scan_ret == -1)
		{
			i = 0;
			while (i < draw.height)
				printf("%.*s\n", draw.width, draw.matrice + i++ * draw.width);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char *av[])
{
	FILE	*file;

	if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (file && !execute(file))
			return (0);
		write(1, "no\n", 3);
	}
	else
		write(1,"nono\n", 5);
	return (1);
}
