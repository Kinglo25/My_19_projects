/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:47:45 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/08 19:55:53 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void		ft_putnbr_hexa(unsigned long n, t_bool capital)
{
	char	*hexa;
	char	*HEXA;

	hexa = "0123456789abcdef";
	HEXA = "0123456789ABCDEF";
	if (n > 15)
		ft_putnbr_hexa(n / 16, capital);
	if (capital)
		ft_putchar(HEXA[n % 16]);
	else
		ft_putchar(hexa[n % 16]);
}

int			find_hexa_len(unsigned long x)
{
	if (x < 16ul)
		return (1);
	return (1 + find_hexa_len(x / 16));
}
