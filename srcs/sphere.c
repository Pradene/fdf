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

static t_point	get_x(t_point p, float radian)
{
	t_point	point;

	point.x = p.x * 1 + p.y * 0 + p.z * 0;
	point.y = p.x * 0 + p.y * cos(radian) + p.z * sin(radian);
	point.z = p.x * 0 + p.y * -sin(radian) + p.z * cos(radian);
	return (point);
}

static t_point	get_y(t_point p, float radian)
{
	t_point	point;

	point.x = p.x * cos(radian) + p.y * 0 + p.z * sin(radian);
	point.y = p.x * 0 + p.y * 1 + p.z * 0;
	point.z = p.x * -sin(radian) + p.y * 0 + p.z * cos(radian);
	return (point);
}

static t_point	get_z(t_point p, float radian)
{
	t_point	point;

	point.x = p.x * cos(radian) + p.y * -sin(radian) + p.z * 0;
	point.y = p.x * sin(radian) + p.y * cos(radian) + p.z * 0;
	point.z = p.x * 0 + p.y * 0 + p.z * 1;
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
	return (point);
}

static t_pos	get_pos(t_data *data, t_point p, int x, int y)
{
	t_pos	pos;
	t_point	point;

	point = get_point(data, p, x, y);
	point = get_x(point, get_radian(data->angleX));
	point = get_y(point, get_radian(data->angleY));
	point = get_z(point, get_radian(data->angleZ));
	pos.x = get_offx(data) + point.x;
	pos.y = get_offy(data) + point.y;
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
