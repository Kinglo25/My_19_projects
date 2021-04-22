#include <mlx.h>
#include <unistd.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	keyboard_event(int keycode, void *param)
{
	t_data	img;

	img.img = mlx_new_image()
	my_mlx_pixel_put()
}

int	main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "fdpdepute");
	mlx_key_hook(win, &keyboard_event, 0);

	mlx_loop(mlx);
}