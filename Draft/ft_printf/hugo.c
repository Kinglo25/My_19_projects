/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hugo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2-221/-23/-24 16:57:57 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/26 14:22:35 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{	
	int  b, y;

	b = printf("printf------> -|%s|-\n", NULL);
	y = printf("ft_printf---> -|%s|-\n",  NULL);
	printf("{%i}\n", b);
	printf("{%i}\n", y);
}
