/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:12:12 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/01 11:22:11 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}


int	print_error(char *error_msg, int built_in)
{
	ft_putstr_fd("Minishell 🐚 :", 2);
	if (built_in)
		perror(error_msg);
	else
		ft_putstr_fd(error_msg, 2);
	return (1);
}
