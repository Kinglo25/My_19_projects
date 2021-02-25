/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:00:21 by lmajerus          #+#    #+#             */
/*   Updated: 2021/02/11 16:00:38 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*last;

	if (c == '\0')
		return (ft_strchr(s, c));
	last = NULL;
	while ((tmp = ft_strchr(s, c)))
	{
		last = tmp;
		s = tmp + 1;
	}
	return (last);
}
