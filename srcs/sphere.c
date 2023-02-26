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

static t_point	get_point(t_data *data, t_point p, int x, int y)
{
	t_point	point;
	float	lat;
	float	lon;
	int32_t	r;

	r = data->map.width * 2 * data->scale + p.z * data->scale_h * 0.5
		* data->scale;
	lon = -PI + (y - 0) * (PI - -PI) / (data->map.height - 1 - 0);
	lat = -PI / 2 + (x - 0) * (PI / 2 - -PI / 2) / (data->map.width - 1 - 0);
	point.x = r * sin(lon) * cos(lat);
	point.y = r * sin(lon) * sin(lat);
	point.z = r * cos(lon);
	return (point);
}

static t_pos	get_pos(t_data *data, t_point p, int x, int y)
{
	t_pos	pos;
	t_point	point;

	pos.x = -1;
	pos.y = -1;
	point = get_point(data, p, x, y);
	point = get_x(point, rad(data->angleX));
	point = get_y(point, rad(data->angleY));
	point = get_z(point, rad(data->angleZ));
	if (point.z < 0)
		return (pos);
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
