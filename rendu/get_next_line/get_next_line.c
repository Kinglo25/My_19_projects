/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:42:59 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/05 21:44:11 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
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
	end_of_line = ft_strchr(s, '\n');
	if (!end_of_line)
		return ;
	while (end_of_line[(i + 1)])
	{
		s[i] = end_of_line[(i + 1)];
		i++;
	}
	s[i] = '\0';
	return ;
}

int	error_free(char *line, char **s, int x)
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

char	*get_next_line(int fd)
{
	int				rv;
	static char		*save;
	char			buff[BUFFER_SIZE + 1];
	char			*line;

	line = NULL;
	rv = 1;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(save, '\n') && rv > 0)
	{
		rv = read(fd, buff, BUFFER_SIZE);//here bug
		buff[rv] = '\0';
		save = ft_free_strjoin(save, buff);
		if (!save)
			return (error_free(line, &save, -1), NULL);
	}
	if (rv < 0)
		return (error_free(line, &save, -1), NULL);
	if (ft_strchr(save, '\n'))
	{
		if (!(line = ft_strdup(save)))
			return (error_free(line, &save, -1), NULL);
		return (line);
	}
	if (!ft_strlen(save))
		return (error_free(NULL, &save, 0), NULL);
	if (!(line = ft_strdup(save)))
		return (error_free(line, &save, -1), NULL);
	return (error_free(NULL, &save, 0), line);
}

// int main(void)
// {
// 	char *m;
// 	int fd = open("test.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	while ((m = get_next_line(fd)) && m)
// 	{
// 		printf("%s\n", m);
// 		free(m);
// 	}
// 	free(m);
// }