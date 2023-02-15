/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:37:02 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/12 20:37:03 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate(uint32_t *angle, int way)
{
	int	max;

	max = 360;
	if (way == -1 && *angle == 0)
		*angle = max - 1;
	else
		*angle = (*angle + way) % max;
}

int	key(int keycode, t_data *data)
{
	if (keycode == 99)
		data->view = (data->view + 1) % 2;
	if (keycode == 114)
		rotate(&data->angle, +1);
	else if (keycode == 101)
		rotate(&data->angle, -1);
	if (keycode == 61)
		data->distance += 1;
	else if (keycode == 45 && data->distance > 1)
		data->distance -= 1;
	if (keycode == 97)
		data->offx -= 1;
	else if (keycode == 100)
		data->offx += 1;
	else if (keycode == 115)
		data->offy += 1;
	else if (keycode == 119)
		data->offy -= 1;
	if (keycode == 65307)
		quit(data);
	return (0);
}
