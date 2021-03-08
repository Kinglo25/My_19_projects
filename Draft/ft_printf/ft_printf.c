/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:06:29 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/07 17:52:44 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] != '%')
		{
			ft_putchar(input[i++]);
			count++;
		}
		else if (input[i++] == '%')
			count += format_specification(input, &flags, args, &i);
	}
	va_end(args);
	return (count);
}
