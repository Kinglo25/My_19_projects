/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:08:39 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/09 19:27:20 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>

typedef enum	e_flags
{
	False,
	True 
}				t_bool;

typedef struct	s_flags
{
	t_bool		bool_width;
	t_bool		bool_precision;
	t_bool		bool_minus;
	t_bool		bool_zeros;
	int			width;
	int			precision;
}				t_flags;

int				ft_printf(const char *input, ...);

int				format_specification(const char *input, t_flags *flags,
				va_list args, int *i);

int				ft_atoi(const char *str, int *i);

void			ft_putnbr(long n);

void			ft_putchar(char c);

void			init_flags_struct(t_flags *flags);

void			width_precision_flags(const char *input,
				t_flags *flags, va_list args, int *i);

void			fill_flags_struct(const char *input, t_flags *flags,
				va_list args, int *i);

int				find_d_len(long x);

int				printf_dec_int(long d, t_flags *flags);

void			width_precision(long d, t_flags *flags, int d_len, int *count);

void			precision_width(long d, t_flags *flags, int d_len, int *count);

int				printf_char(char c, t_flags *flags);

int				printf_str(char *str, t_flags *flags);

int				ft_strlen(const char *s);

int				width_char(char *str, t_flags *flags);

int				char_width(char *str, t_flags *flags);

void			ft_putnbr_hexa(unsigned long n, t_bool capital);

int				printf_ptr(unsigned long ptr, t_flags *flags);

int				printf_ui(unsigned int ui, t_flags *flags);

void			precision_width_ui(unsigned int ui, t_flags *flags,
				int ui_len, int *count);

void			width_precision_ui(unsigned int ui, t_flags *flags,
				int ui_len, int *count);

int				printf_hexa(unsigned long hexa, t_flags *flags,
				t_bool capital);

int				find_hexa_len(unsigned long x);

int				precision_width_hexa(unsigned long hexa, t_flags *flags,
				int hexa_len, t_bool capital);


int				width_precision_hexa(unsigned long hexa, t_flags *flags,
				int hexa_len, t_bool capital);

void			ft_putnbr_ui(unsigned int n);

int				find_ui_len(unsigned int x);

#endif
