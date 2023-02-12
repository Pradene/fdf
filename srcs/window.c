/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:40:44 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/12 20:44:52 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	get_offy(t_data *data, int d)
{
	return (data->offy + HEIGHT / 2
		- ((data->map.height + data->map.width) * d / 2) / 2);
}

int	get_offx(t_data *data, int d)
{
	return (data->offx + WIDTH / 2
		+ ((data->map.height - data->map.width) * d / 2));
}

t_pos	get_pos(t_data *data, t_point p, int d)
{
	t_pos	pos;

	pos.x = get_offx(data, d) + (p.x - p.y) * d;
	pos.y = get_offy(data, d) + (p.y + p.x - p.z) * d / 2;
	return (pos);
}

int	get_rgb(int c1, int c2, int percent)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;

	r = (c1 >> (8 * 2) & 0xFF) + percent * ((c2 >> (8 * 2) & 0xFF)
			- (c1 >> (8 * 2) & 0xFF)) / 100;
	g = (c1 >> (8 * 1) & 0xFF) + percent * ((c2 >> (8 * 1) & 0xFF)
			- (c1 >> (8 * 1) & 0xFF)) / 100;
	b = (c1 >> (8 * 0) & 0xFF) + percent * ((c2 >> (8 * 0) & 0xFF)
			- (c1 >> (8 * 0) & 0xFF)) / 100;
	return ((r << (8 * 2)) + (g << (8 * 1)) + (b << (8 * 0)));
}

static void	render_line(t_data *data, t_point p1, t_point p2)
{
	t_pos	pos1;
	t_pos	pos2;
	int32_t	steps;
	int32_t	i;

	pos1 = get_pos(data, p1, data->distance);
	pos2 = get_pos(data, p2, data->distance);
	if (abs(pos1.x - pos2.x) > abs(pos1.y - pos2.y))
		steps = abs(pos1.x - pos2.x);
	else
		steps = abs(pos1.y - pos2.y);
	i = -1;
	while (++i < steps)
	{
		pixel_put(&data->img,
			pos1.x + (pos2.x - pos1.x) * i / steps,
			pos1.y + (pos2.y - pos1.y) * i / steps,
			get_rgb(p1.color, p2.color, i * 100 / steps));
	}
}

void	reinitialize_img(t_image *img)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			pixel_put(img, x, y, 0x000000);
	}
}

static void	render_map(t_data *data)
{
	int32_t	y;
	int32_t	x;
	t_pos	pos;

	y = -1;
	reinitialize_img(&data->img);
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			if (y + 1 != data->map.height)
				render_line(data, data->map.points[y][x],
					data->map.points[y + 1][x]);
			if (x + 1 != data->map.width)
				render_line(data, data->map.points[y][x],
					data->map.points[y][x + 1]);
			if ((x == data->map.width - 1) && (y == data->map.height - 1))
			{
				pos = get_pos(data, data->map.points[y][x], data->distance);
				pixel_put(&data->img, pos.x, pos.y,
					data->map.points[y][x].color);
			}
		}
	}
}

static int	render(t_data *data)
{
	if (!data->win)
		return (1);
	render_map(data);
	mlx_put_image_to_window(data->id, data->win, data->img.image, 0, 0);
	return (0);
}

void	run(t_data *data)
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
