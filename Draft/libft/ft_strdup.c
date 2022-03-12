/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:53:59 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/03 15:24:27 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	void	*new;

	s_len = ft_strlen(s) + 1;
	new = malloc(s_len);
	if (!new)
		return (NULL);
	return ((char *)ft_memcpy(new, s, s_len));
}
