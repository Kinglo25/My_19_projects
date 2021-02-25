/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:30:52 by lmajerus          #+#    #+#             */
/*   Updated: 2021/02/24 13:57:05 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
	{
		if (!(new = malloc(i + 1)))
			return (NULL);
		new[i] = '\0';
		return (new);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (!(new = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	erase_a_line(s);
	return (new);
}
