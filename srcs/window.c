#include "../includes/fdf.h"

int     get_max(int n1, int n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}

void    render_line(t_data *data, t_point p1, t_point p2)
{
    int32_t step;
    int32_t posx;
    int32_t posy;
    int     max;

    step = -1;
    max = (p2.x - p1.x) % 2 * 2 - 1;
    while (++step < 8)
    {
        posy = HEIGHT / 2 - (data->map.height * 8 / 2) + p1.y * 8 / 2 +
            p1.x * 8 / 2 - (int)data->map.points[p1.y][p1.x].z * 4 + step / 2;
        posx = WIDTH / 2 + ((data->map.height - data->map.width) * 8 / 2) +
            p1.x * 16 / 2 - p1.y * 16 / 2 + max * step;
        if (posx >= 0 && posx <= WIDTH && posy >= 0 && posy <= HEIGHT)
            pixel_put(&data->img, posx, posy, data->map.points[p1.y][p1.x].color);
    }
}

void    render_points(t_data *data)
{
    int32_t y;
    int32_t x;

    y = -1;
    while (++y < data->map.height)
    {
        x = -1;
        while (++x < data->map.width)
        {
            if (y + 1 != data->map.height)
                render_line(data, data->map.points[y][x], data->map.points[y + 1][x]);
            if (x + 1 != data->map.width)
                render_line(data, data->map.points[y][x], data->map.points[y][x + 1]);
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