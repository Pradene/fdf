/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:53:30 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/14 03:57:05 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_offy(t_data *data)
{
	return (data->offy + HEIGHT / 2
		- sin(get_radian(data->angle))
		* (data->map.width * data->distance / 2 / 2)
		- cos(get_radian(data->angle))
		* (data->map.height * data->distance / 2 / 2));
}

static int	get_offx(t_data *data)
{
	return (data->offx + WIDTH / 2
		- cos(get_radian(data->angle))
		* (data->map.width * data->distance / 2)
		+ sin(get_radian(data->angle))
		* (data->map.height * data->distance / 2));
}

static t_pos	get_pos(t_data *data, t_point p, int d)
{
	t_pos	pos;
	float	radian;

	radian = data->angle * (PI / 180);
	pos.x = get_offx(data) + cos(radian) * (p.x * d) - sin(radian) * (p.y * d);
	pos.y = get_offy(data) + sin(radian)
		* (p.x * d / 2) + cos(radian) * (p.y * d / 2)
		- p.z * d / 20;
	return (pos);
}

void	draw_iso(t_data *data)
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
			if (y + 1 != data->map.height)
				render_line(data,
					get_pos(data, data->map.points[y][x], data->distance),
					get_pos(data, data->map.points[y + 1][x], data->distance),
					get_gradient(data->map.points[y][x].color,
						data->map.points[y + 1][x].color));
			if (x + 1 != data->map.width)
				render_line(data,
					get_pos(data, data->map.points[y][x], data->distance),
					get_pos(data, data->map.points[y][x + 1], data->distance),
					get_gradient(data->map.points[y][x].color,
						data->map.points[y][x + 1].color));
			if ((x == data->map.width - 1) && (y == data->map.height - 1))
			{
				pos = get_pos(data, data->map.points[y][x], data->distance);
				pixel_put(&data->img, pos.x, pos.y,
					data->map.points[y][x].color);
			}
		}
	}
}
