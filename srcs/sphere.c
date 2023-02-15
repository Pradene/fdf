/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:52:48 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/14 03:53:18 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_offy(t_data *data)
{
	return (data->offy + HEIGHT / 2);
}

static int	get_offx(t_data *data)
{
	return (data->offx + WIDTH / 2);
}

static float	map(int n, int min1, int max1, float min2, float max2)
{
	return (min2 + (n - min1) * (max2 - min2) / (max1 - min1));
}

static t_point	get_p(float m[4][4], t_point p)
{
	t_point	point;

	point.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0];
	point.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1];
	point.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2];
	return (point);
}

static t_point	get_point(t_data *data, t_point p, int x, int y)
{
	t_point	point;
	float	lat;
	float	lon;
	int32_t	r;

	r = 300 + p.z * 10 / 300;
	lon = map(y, 0, data->map.height - 1, -PI, PI);
	lat = map(x, 0, data->map.width - 1, -PI / 2, PI / 2);
	point.x = r * sin(lon) * cos(lat);
	point.y = r * sin(lon) * sin(lat);
	point.z = r * cos(lon);
	point = get_p(data->matrix, point);
	return (point);
}

static t_pos	get_pos(t_data *data, t_point p, int x, int y)
{
	t_pos	pos;
	t_point	point;

	point = get_point(data, p, x, y);
	pos.x = get_offx(data) + point.x / get_max(1, (-point.z));
	pos.y = get_offy(data) + point.y / get_max(1, (-point.z));
	return (pos);
}

void	draw_sphere(t_data *data)
{
	int32_t	y;
	int32_t	x;
	t_pos	pos;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			pos = get_pos(data, data->map.points[y][x], x, y);
			pixel_put(&data->img, pos.x, pos.y, data->map.points[y][x].color);
		}
	}
}
