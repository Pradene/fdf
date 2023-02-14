#include "../includes/fdf.h"

float	map(int n, int min1, int max1, float min2, float max2)
{
	return (min2 + (n - min1) * (max2 - min2) / (max1 - min1));
}

static t_pos    get_pos(t_data *data, t_point p, int x , int y)
{
	t_pos	pos;
    float   lat;
    float   lon;
    int32_t r;

    r = 300;
	lon = map(y, 0, data->map.height - 1, -PI, PI);
    lat = map(x, 0, data->map.width - 1, -PI / 2, PI / 2);
    pos.x = WIDTH / 2 + (r + p.z / 10) * sin(lon) * cos(lat);
    pos.y = HEIGHT / 2 + (r + p.z / 10) * sin(lon) * sin(lat);
	return (pos);
}

void	draw_sphere(t_data *data)
{
	int32_t	y;
	int32_t	x;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
            if (y + 1 != data->map.height)
				render_line(data,
                    get_pos(data, data->map.points[y][x], x, y),
					get_pos(data, data->map.points[y + 1][x], x, y + 1),
                    get_gradient(0xFFFFFF, 0xFFFFFF));
			if (x + 1 != data->map.width)
				render_line(data,
                    get_pos(data, data->map.points[y][x], x, y),
					get_pos(data, data->map.points[y][x + 1], x + 1, y),
                    get_gradient(0xFFFFFF, 0xFFFFFF));
		}
	}
}
