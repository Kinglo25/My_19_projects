/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:55:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/09 19:29:03 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_ptr(unsigned long ptr, t_flags *flags)
{
	int		count;
	int		hexa_len;

	count = 0;
	hexa_len = find_hexa_len(ptr) + 2;
	if (flags->bool_minus)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_hexa(ptr, False);
		while (flags->width-- > hexa_len)
		{
			ft_putchar(' ');
			count++;
		}
	}
	else
	{
		while (flags->width-- > hexa_len)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_hexa(ptr, False);
	}
	return (count + hexa_len);
}