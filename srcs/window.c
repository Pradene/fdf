#include "../includes/fdf.h"

void    render_points(t_data *data)
{
    int32_t y;
    int32_t x;
    int     height;

    y = -1;
    while (++y < data->map.height)
    {
        x = -1;
        while (++x < data->map.width)
        {
            height = (int)data->map.points[y][x].z;
            pixel_put(&data->img, WIDTH / 2 - data->map.width / 2 * 10 + x * 10,
                HEIGHT / 2 - data->map.height / 2 * 10 + y * 10 + height,
                0xFFFF00);
        }
    }
}

static int  render(t_data *data)
{
    if (!data->win)
        return (1);
    render_points(data);
    mlx_put_image_to_window(data->id, data->win, data->img.image, 0, 0);
    return (0);
}

void    window(t_data *data)
{
    data->id = mlx_init();
    if (!data->id)
        quit(data);
    data->win = mlx_new_window(data->id, WIDTH, HEIGHT, "FDF");
    data->img.image = mlx_new_image(data->id, WIDTH, HEIGHT);
    data->img.data = mlx_get_data_addr(data->img.image, &data->img.bpp,
        &data->img.size_line, &data->img.endian);
    mlx_loop_hook(data->id, &render, data);
    mlx_hook(data->win, 2, 1L << 0, &key, data);
	mlx_hook(data->win, 17, 0, &quit, data);
    mlx_loop(data->id);
}