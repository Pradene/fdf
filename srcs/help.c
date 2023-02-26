/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:03:58 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/26 09:04:31 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_background(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH / 6)
		{
			pixel_put(&data->img, x, y,
				get_rgb(0x404040, get_pix_color(&data->img, x, y), 25));
		}
	}
}

void	help(t_data *data)
{
	set_background(data);
	mlx_string_put(data->id, data->win, 24, 24, 0xFFFFFF, "H: Toggle Help");
	mlx_string_put(data->id, data->win, 24, 40, 0xFFFFFF, "ESC: QUIT");
	mlx_string_put(data->id, data->win, 24, 56, 0xFFFFFF, "W: Move UP");
	mlx_string_put(data->id, data->win, 24, 72, 0xFFFFFF, "S: Move DOWN");
	mlx_string_put(data->id, data->win, 24, 88, 0xFFFFFF, "A: Move LEFT");
	mlx_string_put(data->id, data->win, 24, 104, 0xFFFFFF, "D: Move RIGHT");
	mlx_string_put(data->id, data->win, 24, 120, 0xFFFFFF, "E: Rotate Y axis");
	mlx_string_put(data->id, data->win, 24, 136, 0xFFFFFF, "R: Rotate X axis");
	mlx_string_put(data->id, data->win, 24, 152, 0xFFFFFF, "T: Rotate Z axis");
	mlx_string_put(data->id, data->win, 24, 168, 0xFFFFFF, "C: Change View");
	mlx_string_put(data->id, data->win, 24, 184, 0xFFFFFF, "-: Dezoom");
	mlx_string_put(data->id, data->win, 24, 200, 0xFFFFFF, "+: Zoom");
	mlx_string_put(data->id, data->win, 24, 216, 0xFFFFFF, "F: Increase H");
	mlx_string_put(data->id, data->win, 24, 232, 0xFFFFFF, "G: Decrease H");
}
