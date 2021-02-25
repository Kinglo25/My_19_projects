/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:02:09 by lmajerus          #+#    #+#             */
/*   Updated: 2021/02/11 16:02:42 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(new = malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (i < len && start + i < ft_strlen(s))
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}
