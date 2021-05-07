/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:42:59 by lmajerus          #+#    #+#             */
/*   Updated: 2021/04/22 19:23:01 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	erase_a_line(char *s)
{
	char	*end_of_line;
	size_t	i;

	i = 0;
	end_of_line = ft_strchr(s, '\n');
	if (!(end_of_line))
		return ;
	while (end_of_line[(i + 1)])
	{
		s[i] = end_of_line[(i + 1)];
		i++;
	}
	s[i] = '\0';
	return ;
}

static char	*ft_strdup(char *s)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
	{
		new = malloc(i + 1);
		if (new == NULL)
			return (NULL);
		new[i] = '\0';
		return (new);
	}
	while (s[i] && s[i] != '\n')
		i++;
	new = malloc(i + 1);
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		new[i] = s[i];
	new[i] = '\0';
	erase_a_line(s);
	return (new);
}

static int	error_free(char **s, int x)
{
	if (s)
	{
		if (x == 0)
		{
			free(*s);
			*s = NULL;
			return (0);
		}
		if (x == -1)
		{
			free(*s);
			*s = NULL;
			return (-1);
		}
	}
	return (19);
}

static int	gnl_2(char **save, char **line, int rv)
{
	if (rv < 0)
		return (error_free(save, -1));
	if (ft_strchr(*save, '\n'))
	{
		*line = ft_strdup(*save);
		if (*line == NULL)
			return (error_free(save, -1));
		return (1);
	}
	*line = ft_strdup(*save);
	if (*line == NULL)
		return (error_free(save, -1));
	return (error_free(save, 0));
}

int	get_next_line(int fd, char **line)
{
	int				rv;
	static char		*save;
	char			buff[BUFFER_SIZE + 1];

	rv = 1;
	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!ft_strchr(save, '\n'))
	{
		while (rv > 0)
		{
			rv = read(fd, buff, BUFFER_SIZE);
			buff[rv] = '\0';
			save = ft_free_strjoin(save, buff);
			if (save == NULL)
				return (error_free(&save, -1));
		}
	}
	return (gnl_2(&save, line, rv));
}
