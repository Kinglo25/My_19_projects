/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:03:08 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/09 19:28:03 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_ui(unsigned int ui, t_flags *flags)
{
	int		count;
	int		ui_len;

	count = 0;
	ui_len = find_ui_len(ui);
	if (ui == 0 && flags->bool_precision && flags->precision == 0)
	{
		while (flags->width-- && ++count)
			ft_putchar(' ');
		return (count);
	}
	if (ui_len > flags->precision)
		flags->width -= ui_len;
	else
		flags->width -= flags->precision;
	if (flags->precision < 0)
	{
		if (flags->bool_minus == False && flags->bool_zeros == False)
			while (flags->width-- > 0 && ++count)
				ft_putchar(' ');
		if (flags->bool_zeros)
		{
			while (flags->width-- > 0 && ++count)
				ft_putchar('0');
			ft_putnbr_ui(ui);
		}
		if (!flags->bool_zeros)
		{
			ft_putnbr_ui(ui);
			while (flags->width-- > 0 && ++count)
				ft_putchar(' ');
		}
		return (count + ui_len);
	}
	if (flags->bool_precision == True)
		flags->bool_zeros = False;
	if (flags->bool_minus == True)
		precision_width_ui(ui, flags, ui_len, &count);
	else if (flags->bool_minus == False)
		width_precision_ui(ui, flags, ui_len, &count);
	return(count + ui_len);
}

void	precision_width_ui(unsigned int ui, t_flags *flags, int ui_len, int *count)
{
	while (flags->precision-- > ui_len)
	{
		ft_putchar('0');
		(*count)++;
	}
	ft_putnbr_ui(ui);
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		(*count)++;
	}
	return ;
}

void	width_precision_ui(unsigned int ui, t_flags *flags, int ui_len, int *count)
{
	while (flags->width-- > 0)
	{
		if (flags->bool_zeros == True)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(*count)++;
	}
	while (flags->precision-- > ui_len)
	{
		ft_putchar('0');
		(*count)++;
	}
	ft_putnbr_ui(ui);
	return ;
}