/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:05:58 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/08 19:04:35 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_hexa(unsigned long hexa, t_flags *flags, t_bool capital)
{
	int		count;
	int		hexa_len;

	count = 0;
	hexa_len = find_hexa_len(hexa);
	if (flags->precision == 0 && hexa == 0 && flags->bool_precision)
		return (0);
	if (hexa_len > flags->precision)
		flags->width -= (hexa_len + count);
	else
		flags->width -= (flags->precision + count);
	if (flags->bool_precision == true)
		flags->bool_zeros = false;
	if (flags->bool_minus == true)
		count += precision_width_hexa(hexa, flags, hexa_len, capital);
	else if (flags->bool_minus == false)
		count += width_precision_hexa(hexa, flags, hexa_len, capital);
	return(count + hexa_len);
}

int		precision_width_hexa(unsigned long hexa, t_flags *flags,
		int hexa_len, t_bool capital)
{
	int		count;

	count = 0;
	while (flags->precision-- > hexa_len)
	{
		ft_putchar('0');
		count++;
	}
	ft_putnbr_hexa(hexa, capital);
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int		width_precision_hexa(unsigned long hexa, t_flags *flags,
		int hexa_len, t_bool capital)
{
	int		count;

	count = 0;
	while (flags->width-- > 0)
	{
		if (flags->bool_zeros == true)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count++;
	}
	while (flags->precision-- > hexa_len)
	{
		ft_putchar('0');
		count++;
	}
	ft_putnbr_hexa(hexa, capital);
	return (count);
}