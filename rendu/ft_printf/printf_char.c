/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:14:20 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/10 13:10:58 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_char(char c, t_flags *flags)
{
	int		count;

	count = 1;
	if (flags->width > (INT_MAX - 1))
		return (-1);
	if (flags->bool_minus)
	{
		ft_putchar(c);
		while (flags->width-- > 1)
		{
			ft_putchar(' ');
			count++;
		}
	}
	else
	{
		while (flags->width-- > 1)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar(c);
	}
	return (count);
}
