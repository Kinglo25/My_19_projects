/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hugo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2-221/-23/-24 16:57:57 by lmajerus          #+#    #+#             */
/*   Updated: 2-221/-23/-28 21:35:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *x = "eee";
	int  b, y;

	b = printf("printf------> -|%p|-\n", x);
	y = ft_printf("ft_printf---> -|%p|-\n", x);
	printf("{%i}\n", b);
	printf("{%i}\n", y);
}