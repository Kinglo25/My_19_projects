/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:03:08 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/08 19:52:46 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_ui(unsigned int ui, t_flags *flags)
{
	int		count;
	int		ui_len;

	count = 0;
	ui_len = find_ui_len(ui);
	if (flags->precision == 0 && ui == 0 && flags->bool_precision)
		return (0);
	if (ui_len > flags->precision)
		flags->width -= (ui_len + count);
	else
		flags->width -= (flags->precision + count);
	if (flags->bool_precision == true)
		flags->bool_zeros = false;
	if (flags->bool_minus == true)
		precision_width_ui(ui, flags, ui_len, &count);
	else if (flags->bool_minus == false)
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
	int		tmp;

	tmp = *count;
	while (flags->width-- > 0)
	{
		if (flags->bool_zeros == true)
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