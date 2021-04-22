#include <mlx.h>

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixels;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct s_coord
{
	int	x;
	int y;
}				t_coord;

typedef struct s_triangle
{
	t_coord a;
	t_coord b;
	t_coord	c;
}				t_triangle;

void	draw_triangle(void *mlx, t_data *img, int height, int widht)
{
	t_triangle triangle;

	triangle.a.x = 122;
	triangle.a.y = 0;
	triangle.b.x = 0;
	triangle.b.y = 255;
	triangle.c.x = 255;
	triangle.c.y = 255;

}

void	my_mlx_pixel_put(t_data *data, int x, int y, color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 255, 255, "Yes");
	img.img = mlx_new_image(mlx, 255, 255);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_lenght,
								 &img.endian);
	draw_triangle(mlx, &img, 255, 255)
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}