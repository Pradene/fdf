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

static void	reinitialize_img(t_image *img)
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

static void	draw_view(t_data *data)
{
	if (data->view == 0)
		draw_iso(data);
	else if (data->view == 1)
		draw_sphere(data);
}

static int	render(t_data *data)
{
	if (!data->win)
		return (1);
	data->angleX += 1;
	data->angleY += 1;
	data->angleZ += 1;
	reinitialize_img(&data->img);
	draw_view(data);
	mlx_put_image_to_window(data->id, data->win, data->img.image, 0, 0);
	if (data->help)
		help(data);
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
