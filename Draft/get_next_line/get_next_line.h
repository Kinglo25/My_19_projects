/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:16:00 by lmajerus          #+#    #+#             */
/*   Updated: 2021/04/21 19:37:31 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(char *str);


char	*ft_free_strjoin(char *s1, char *s2);


#endif
