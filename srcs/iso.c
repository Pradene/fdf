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
		- sin(rad(data->angle_y))
		* (data->map.width * data->dist * data->scale / 2 / 2)
		- cos(rad(data->angle_y))
		* (data->map.height * data->dist * data->scale / 2 / 2));
}

static int	get_offx(t_data *data)
{
	return (data->offx + WIDTH / 2
		- cos(rad(data->angle_y))
		* (data->map.width * data->dist * data->scale / 2)
		+ sin(rad(data->angle_y))
		* (data->map.height * data->dist * data->scale / 2));
}

static t_pos	get_pos(t_data *data, t_point p, float d)
{
	t_pos	pos;
	float	radian;

	radian = rad(data->angle_y);
	pos.x = get_offx(data) + cos(radian) * (p.x * d) - sin(radian) * (p.y * d);
	pos.y = get_offy(data) + sin(radian)
		* (p.x * d / 2) + cos(radian) * (p.y * d / 2)
		- p.z * data->scale_h * data->scale;
	return (pos);
}

static void	render_lines(t_data *data, int x, int y)
{
	t_pos	pos;

	if (y + 1 != data->map.height)
		render_line(data,
			get_pos(data, data->map.points[y][x], data->dist * data->scale),
			get_pos(data, data->map.points[y + 1][x], data->dist * data->scale),
			get_gradient(data->map.points[y][x].color,
				data->map.points[y + 1][x].color));
	if (x + 1 != data->map.width)
		render_line(data,
			get_pos(data, data->map.points[y][x], data->dist * data->scale),
			get_pos(data, data->map.points[y][x + 1], data->dist * data->scale),
			get_gradient(data->map.points[y][x].color,
				data->map.points[y][x + 1].color));
	if ((x == data->map.width - 1) && (y == data->map.height - 1))
	{
		pos = get_pos(data, data->map.points[y][x], data->dist * data->scale);
		pixel_put(&data->img, pos.x, pos.y,
			data->map.points[y][x].color);
	}
}

void	draw_iso(t_data *data)
{
	int32_t	y;
	int32_t	x;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
			render_lines(data, x, y);
	}
}
