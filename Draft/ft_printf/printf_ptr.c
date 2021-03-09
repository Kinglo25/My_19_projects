/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:55:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/09 21:38:18 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_ptr(unsigned long ptr, t_flags *flags)
{
	int		count;
	int		hexa_len;

	count = 0;
	hexa_len = find_hexa_len(ptr) + 2;
	if (hexa_len > flags->precision)
		flags->width -= hexa_len;
	else
		flags->width -= (flags->precision + 2);
	if (!ptr)
	{
		if (flags->bool_precision)
			flags->width++;
		while (flags->width-- > 0)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar('0');
		ft_putchar('x');
		while (flags->precision-- > 0)
		{
			ft_putchar('0');
			count++;
		}
		if (!flags->bool_precision && ++count)
			ft_putchar('0');
		return (count + 2);
	}
	if (flags->bool_minus)
	{
		ft_putchar('0');
		ft_putchar('x');
		while (flags->precision-- > hexa_len)
		{
			ft_putchar('0');
			count++;
		}
		ft_putnbr_hexa(ptr, False);
		while (flags->width-- > 0)
		{
			ft_putchar(' ');
			count++;
		}
	}
	else
	{
		while (flags->width-- > 0)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar('0');
		ft_putchar('x');
		while (flags->precision-- > (hexa_len - 2))
		{
			ft_putchar('0');
			count++;
		}
		ft_putnbr_hexa(ptr, False);
	}
	return (count + hexa_len);
}