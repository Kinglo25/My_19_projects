/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:08:39 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/04 19:01:48 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>

typedef enum {false, true} bool;

typedef struct	s_flags
{
	bool			bool_width;
	bool			bool_star;
	bool			bool_precision;
	bool			bool_minus;
	bool			bool_zeros;
	unsigned int	width;
	unsigned int	star;
	unsigned int	precision;
}				t_flags;

int		ft_printf(const char *input, ...);

#endif