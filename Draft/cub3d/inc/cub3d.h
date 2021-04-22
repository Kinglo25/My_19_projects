/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:09:22 by lmajerus          #+#    #+#             */
/*   Updated: 2021/04/22 17:47:14 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 1024

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <sys/stat.h>
# include <stdlib.h>

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_map_info
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*S;
	char	**map;
	int		C;
	int		F;
	t_coord	R;
	int		fd;
}				t_map_info;

// Get_next_line
int		get_next_line(const int fd, char **line);

// Utils
int		is_space(char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_free_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		create_rgb(int r, int g, int b);
int		ft_atoi(const char *input, int *i);

// Parser
void	ft_error(char *strerror, t_map_info *map);

#endif
