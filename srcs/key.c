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

int	_key(int keycode, t_data *data)
{
	if (keycode == 104)
		data->help = (data->help + 1) % 2;
	if (keycode == 99)
		data->view = (data->view + 1) % 2;
	if (keycode == 65307)
		quit(data);
	return (0);
}

int	key(int keycode, t_data *data)
{
	_key(keycode, data);
	if (keycode == 116)
		data->angleZ += 1;
	if (keycode == 114)
		data->angleX += 1;
	if (keycode == 101)
		data->angleY += 1;
	if (keycode == 61)
		data->scale += 0.01;
	else if (keycode == 45 && data->scale > 0.1)
		data->scale -= 0.01;
	if (keycode == 102)
		data->scale_h += 0.01;
	else if (keycode == 103)
		data->scale_h -= 0.01;
	if (keycode == 97)
		data->offx -= 1;
	else if (keycode == 100)
		data->offx += 1;
	else if (keycode == 115)
		data->offy += 1;
	else if (keycode == 119)
		data->offy -= 1;
	return (0);
}
