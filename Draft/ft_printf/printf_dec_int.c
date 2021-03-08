/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:19:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/08 21:33:44 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_dec_int(long d, t_flags *flags)
{
	int		count;
	int		d_len;

	count = 0;
	if (d < 0)
	{
		count++;
		d *= -1;
	}
	d_len = find_d_len(d);
	if (flags->precision == 0 && d == 0 &&
	flags->bool_precision)
	{
		while (flags->width-- > 0 && ++count)
			ft_putchar(' ');
		return (count);
	}
	if (flags->precision < 0)
	{
		if (count)
			ft_putchar('-');
		ft_putnbr(d);
		return (count + d_len);
	}
	if (d_len > flags->precision)
		flags->width -= (d_len + count);
	else
		flags->width -= (flags->precision + count);
	if (flags->bool_precision == true)
		flags->bool_zeros = false;
	if (flags->bool_minus == true)
		precision_width(d, flags, d_len, &count);
	else if (flags->bool_minus == false)
		width_precision(d, flags, d_len, &count);
	return(count + d_len);
}

void	precision_width(long d, t_flags *flags, int d_len, int *count)
{
	if (*count == 1)
		ft_putchar('-');
	while (flags->precision-- > d_len)
	{
		ft_putchar('0');
		(*count)++;
	}
	ft_putnbr(d);
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		(*count)++;
	}
	return ;
}

void	width_precision(long d, t_flags *flags, int d_len, int *count)
{
	int		tmp;

	tmp = *count;
	while (flags->width-- > 0)
	{
		if (flags->bool_zeros == true)
		{
			if (tmp == 1 && (tmp = 2))
				ft_putchar('-');
			ft_putchar('0');
		}
		else
			ft_putchar(' ');
		(*count)++;
	}
	if (tmp == 1)
		ft_putchar('-');
	while (flags->precision-- > d_len)
	{
		ft_putchar('0');
		(*count)++;
	}
	ft_putnbr(d);
	return ;
}