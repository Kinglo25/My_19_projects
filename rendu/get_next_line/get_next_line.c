/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:42:59 by lmajerus          #+#    #+#             */
/*   Updated: 2021/02/24 13:49:17 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!(s3 = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			s3[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	if (s2)
		while (s2[i])
			s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

void	erase_a_line(char *s)
{
	char	*end_of_line;
	size_t	i;

	i = 0;
	if (!(end_of_line = ft_strchr(s, '\n')))
		return ;
	while (end_of_line[(i + 1)])
	{
		s[i] = end_of_line[(i + 1)];
		i++;
	}
	s[i] = '\0';
	return ;
}

int		error_free(char * line, char **s, int x)
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
			free(line);
			free(*s);
			*s = NULL;
			return (-1);
		}
	}
	return (19);
}

char*		get_next_line(int fd)
{
	int				rv;
	static char		*save;
	char			buff[BUFFER_SIZE + (rv = 1)];
	char			*tmp;
	char			*line = NULL;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(save, '\n') && (rv = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rv] = '\0';
		tmp = save;
		if (!(save = ft_free_strjoin(tmp, buff)))
			return (error_free(line, &save, -1), NULL);
	}
	if (rv < 0)
		return (error_free(line, &save, -1), NULL);
	if (ft_strchr(save, '\n') && *save != '\n')
	{
		if (!(line = ft_strdup(save)))
			return (error_free(line, &save, -1), NULL);
		return (line);
	}
	if (!save)
		return NULL;
	if (!(line = ft_strdup(save)))
		return (error_free(line, &save, -1), NULL);
	return (error_free(NULL, &save, 0), line);
}

int main(void)
{
	char *m;
	int fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	while ((m = get_next_line(fd)) && m)
	{
		printf("%s\n", m);
		free(m);
	}
	free(m);
}