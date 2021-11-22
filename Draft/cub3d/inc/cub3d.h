/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:09:22 by lmajerus          #+#    #+#             */
/*   Updated: 2021/11/22 15:26:24 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KPRESS 2
# define KCLICK	3
# define MCLICK	4
# define MPRESS 5
# define MMOVE 	6
# define W 13
# define S 1
# define A 0
# define D 2
# define T 17
# define J 38
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ESC 53
# define WHEELUP 5
# define WHEELDOWN 4
# define WHEELCLICK 3
# define RIGHTCLICK 2
# define LEFTCLICK 1
# define BUFFER_SIZE 1024
# define TEXTWIDTH 64
# define TEXTHEIGHT 64
# define MS 0.5
# define TSP 0.08
# define PCT 0.16

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>  

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_map_info
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**map;
	int		c;
	int		f;
	t_coord	r;
	int		fd;
	int		n;
	size_t	map_len;
	int		error;
	double	px;
	double	py;
	double	dx;
	double	dy;
	double	pos_x;
	double	pos_y;
}				t_map_info;

typedef struct s_data {
	void		*img;
	char		*addr;
	void		*mlx;
	void		*win;
	int			bpp;
	int			line_len;
	int			endian;
	t_map_info	*m;
	void		*wall_n;
	void		*wall_s;
	void		*wall_e;
	void		*wall_w;
	int			*text[4];
	double		cam_x;
	double		rdx;
	double		rdy;
	int			map_x;
	int			map_y;
	double		ddx;
	double		ddy;
	int			step_x;
	int			step_y;
	double		sdx;
	double		sdy;
	int			hit;
	int			side;
	double		pwd;
	int			line_h;
	int			draw_e;
	int			draw_s;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		text_pos;
	double		step;
	int			color;
	int			text_num;
	int			bords;
	double		o_dx;
	double		o_px;
}				t_data;

// Get_next_line
int		get_next_line(const int fd, char **line);

// Utils
int		is_space(char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_free_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		create_rgb(int t, int r, int g, int b);
int		ft_atoi(const char *input, size_t *i);
void	*ft_memset(void *s, int c, size_t n);

// Parser
int		ft_error(char *strerror, t_map_info *map);
void	get_textures(char *line, char **ptr_from_map, t_map_info *map);
void	get_floor_ceiling(char *line, int *int_from_map, t_map_info *map);
void	get_resolution(char *line, t_map_info *map);
void	get_map_len(char *str, t_map_info *map);
void	get_map(char *line, t_map_info *map);
void	parser(t_map_info *map);

//mlx
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		raycasting(t_data *c);
int		mlx(t_map_info *map);

// Raycaster
void	find_side(t_data *c, int id);
void	draw_ceil_floor(t_data *c);

// move and event
void	clc_move(int key, t_data *s, int *y, int *x);
void	move_updown(int key, t_data *s);
void	move_leftright(int key, t_data *s);
void	turn_leftright(int key, t_data *s);
int		key_hook(int key, t_data *c);
int		ft_exit_button(t_data *c);
int		ft_exit(t_data *c, int ret);

// draw
void	draw_ceil_floor(t_data *c);
void	draw_line(t_data *c, int x);

#endif
