#include <mlx.h>
#include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

int	key_hook(int keycode, t_data *init)
{
	if (keycode == 53)
	{
		mlx_destroy_window(init->mlx, init->win);
	}
	else
		printf("%i\n", keycode);
	return (1);
}

int main()
{
	t_data init;

	init.mlx = mlx_init();
	init.win = mlx_new_window(init.mlx, 255, 255, "yo");
	mlx_key_hook(init.win, key_hook, &init);
	mlx_loop(init.mlx);
}

