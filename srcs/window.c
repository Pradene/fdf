#include "../includes/fdf.h"

void    window(t_data *data)
{
    data->id = mlx_init();
    if (!data->id)
        quit(data);
    data->win = mlx_new_window(data->id, 900, 600, "FDF");
    mlx_hook(data->win, 2, 1L << 0, &key, data);
	mlx_hook(data->win, 17, 0, &quit, data);
    mlx_loop(data->id);
}