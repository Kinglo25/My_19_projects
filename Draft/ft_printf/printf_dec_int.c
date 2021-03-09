/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:19:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/09 19:26:28 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_dec_int(long d, t_flags *flags)
{
	int		count;
	int		d_len;
	int		tmp;

	count = 0;
	if (d < 0 && ++count)
		d *= -1;
	d_len = find_d_len(d);
	if (flags->precision == 0 && d == 0 &&
	flags->bool_precision)
	{
		while (flags->width-- > 0 && ++count)
			ft_putchar(' ');
		return (count);
	}
	if (d_len > flags->precision)
		flags->width -= (d_len + count);
	else
		flags->width -= (flags->precision + count);
	if (flags->precision < 0)
	{
		tmp = count;
		if (flags->bool_minus == False && flags->bool_zeros == False)
			while (flags->width-- > 0 && ++count)
				ft_putchar(' ');
		if (tmp == 1)
			ft_putchar('-');
		if (flags->bool_zeros)
		{
			while (flags->width-- > 0 && ++count)
				ft_putchar('0');
			ft_putnbr(d);
		}
		if (!flags->bool_zeros)
		{
			ft_putnbr(d);
			while (flags->width-- > 0 && ++count)
				ft_putchar(' ');
		}
		return (count + d_len);
	}
	if (flags->bool_precision == True)
		flags->bool_zeros = False;
	if (flags->bool_minus == True)
		precision_width(d, flags, d_len, &count);
	else if (flags->bool_minus == False)
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
		if (flags->bool_zeros == True)
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