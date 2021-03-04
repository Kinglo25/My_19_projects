/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:59:11 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/04 18:15:49 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags_struct(t_flags flags)
{
	flags.bool_minus = false;
	flags.bool_precision = false;
	flags.bool_star = false;
	flags.bool_width = false;
	flags.bool_zeros = false;
	flags.precision = 0;
	flags.star = 0;
	flags.width = 0;
	return ;
}
