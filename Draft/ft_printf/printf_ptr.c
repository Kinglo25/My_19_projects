/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:55:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:53 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_ptr(unsigned long ptr, t_flags *flags)
{
	int		count;

	count = 11;
	if (flags->bool_minus)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_hexa(ptr, false);
		while (flags->width-- > 11)
		{
			ft_putchar(' ');
			count++;
		}
	}
	else
	{
		while (flags->width-- > 11)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_hexa(ptr, false);
	}
	return (count);
}