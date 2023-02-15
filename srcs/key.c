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

// static void	rotateX(float m[4][4], uint32_t angle)
// {
// 	m[0][0] = m[0][0] * 1 + m[0][1] * 0 + m[0][2] * 0;
// 	m[0][1] = m[0][0] * 0 + m[0][1] * cos(angle) + m[0][2] * sin(angle);
// 	m[0][2] = m[0][0] * 0 + m[0][1] * -sin(angle) + m[0][2] * cos(angle);

// 	m[1][0] = m[1][0] * 1 + m[1][1] * 0 + m[1][2] * 0;
// 	m[1][1] = m[1][0] * 0 + m[1][1] * cos(angle) + m[1][2] * sin(angle);
// 	m[1][2] = m[1][0] * 0 + m[1][1] * -sin(angle) + m[1][2] * cos(angle);

// 	m[2][0] = m[2][0] * 1 + m[2][1] * 0 + m[2][2] * 0;
// 	m[2][1] = m[2][0] * 0 + m[2][1] * cos(angle) + m[2][2] * sin(angle);
// 	m[2][2] = m[2][0] * 0 + m[2][1] * -sin(angle) + m[2][2] * cos(angle);
// }

// static void	rotate(uint32_t *angle, int way)
// {
// 	int	max;

// 	max = 360;
// 	if (way == -1 && *angle == 0)
// 		*angle = max - 1;
// 	else
// 		*angle = (*angle + way) % max;
// }

int	key(int keycode, t_data *data)
{
	if (keycode == 99)
		data->view = (data->view + 1) % 2;
	if (keycode == 116)
		data->angleZ = data->angleZ + 1;
	if (keycode == 114)
		data->angleX = data->angleX + 1;
	if (keycode == 101)
		data->angleY = data->angleY + 1;
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
