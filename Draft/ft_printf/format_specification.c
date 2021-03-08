/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:59:40 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/08 19:48:31 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_specification(const char *input, t_flags *flags,
			va_list args, int *i)
{
	int		count;

	count = 0;
	fill_flags_struct(input, flags, args, i);
	if (input[*i] == 'c')
		count = printf_char(va_arg(args, int), flags);
	else if (input[*i] == 's')
		count = printf_str(va_arg(args, char*), flags);
	else if (input[*i] == 'p')
		count = printf_ptr(va_arg(args, unsigned int), flags);
	else if (input[*i] == 'd' || input[*i] == 'i')
		count = printf_dec_int(va_arg(args, int), flags);
	else if (input[*i] == 'u')
		count = printf_ui(va_arg(args, unsigned int), flags);
	else if (input[*i] == 'x')
		count = printf_hexa(va_arg(args, unsigned int), flags, false);
	else if (input[*i] == 'X')
		count = printf_hexa(va_arg(args, unsigned int), flags, true);
	(*i)++;
	return (count);
}