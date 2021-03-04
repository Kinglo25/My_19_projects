/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:06:29 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/04 19:38:47 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *input, ...)
{
	size_t	count;
	va_list	args;
	t_flags	flags;
	size_t	i;

	i = 0;
	count = 0;
	va_start(args, input[i]);
	while (input[i])
	{
		if (input[i] != '%')
		{
			ft_putchar(input[i++]);
			count++;
		}
		else
	}
	va_end(args);
	return (count);
}

// remplace count par i. surment ps besoin des deux
