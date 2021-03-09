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
#include <limits.h>

int		main(void)
{	
	char *x ="hello";
	int  b, y;
	int z = INT_MAX;

	b = printf("printf------> -|%*.15p|-\n", z, 1234);
	y = ft_printf("ft_printf---> -|%*.15p|-\n", z, 1234);
	printf("{%i}\n", b);
	printf("{%i}\n", y);
}