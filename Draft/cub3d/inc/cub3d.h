/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:09:22 by lmajerus          #+#    #+#             */
/*   Updated: 2021/05/11 17:05:54 by lmajerus         ###   ########.fr       */
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
	int	x;
	int	y;
}				t_coord;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	int		n;
	size_t	map_len;
	int		error;
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
int		ft_atoi(const char *input, size_t *i);
void	*ft_memset(void *s, int c, size_t n);

// Parser
int		ft_error(char *strerror, t_map_info *map);
void	get_textures(char *line, char **ptr_from_map, t_map_info *map);
void	get_floor_ceiling(char *line, int *int_from_map, t_map_info *map);
void	get_resolution(char *line, t_map_info *map);
void	get_map_len(char *str, t_map_info *map);
void	get_map(char *line, t_map_info *map);


#endif
