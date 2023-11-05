/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:16:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/02/24 14:33:44 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPEN_MAX 2048
# define BUFFER_SIZE 2048
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char*	get_next_line(const int fd);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(char *str);

void	erase_a_line(char *s);

char	*ft_free_strjoin(char *s1, char *s2);

int		error_free(char * line, char **s, int x);

char	*ft_strdup(char *s);

#endif
