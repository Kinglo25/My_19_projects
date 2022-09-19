/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:31:59 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/26 17:03:45 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
