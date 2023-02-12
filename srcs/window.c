#include "../includes/fdf.h"

int     get_max(int n1, int n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}

int    get_offy(t_data *data, int d)
{
    return (data->offy + HEIGHT / 2 - ((data->map.height + data->map.width) * d / 2) / 2);
}

int    get_offx(t_data *data, int d)
{
    return (data->offx + WIDTH / 2 + ((data->map.height - data->map.width) * d / 2));
}

t_pos   get_pos(t_data *data, t_point p, int d)
{
    t_pos   pos;

    pos.x = get_offx(data, d) + (p.x - p.y) * d;
    pos.y = get_offy(data, d) + (p.y + p.x - p.z) * d / 2;
    return (pos);
}

void    render_line(t_data *data, t_point p1, t_point p2)
{
    t_pos   pos1;
    t_pos   pos2;
    int32_t steps;
    int32_t i;

    pos1 = get_pos(data, p1, 12);
    pos2 = get_pos(data, p2, 12);
    if (abs(pos1.x - pos2.x) > abs(pos1.y - pos2.y))
        steps = abs(pos1.x - pos2.x);
    else
        steps = abs(pos1.y - pos2.y);
    i = -1;
    while (++i < steps)
    {
        if ((pos1.x + (pos2.x - pos1.x) * i / steps) < 0
            || (pos1.x + (pos2.x - pos1.x) * i / steps) >= WIDTH
            || (pos1.y + (pos2.y - pos1.y) * i / steps) < 0
            || (pos1.y + (pos2.y - pos1.y) * i / steps) >= HEIGHT)
            continue ;
        pixel_put(&data->img,
        pos1.x + (pos2.x - pos1.x) * i / steps,
        pos1.y + (pos2.y - pos1.y) * i / steps,
        p1.color);
    }
}

void    render_map(t_data *data)
{
    int32_t y;
    int32_t x;
    int32_t posx;
    int32_t posy;

    y = -1;
    posx = 0;
    posy = 0;
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
    render_map(data);
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