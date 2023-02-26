/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:38:20 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/14 03:52:32 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	quit(t_data *data)
{
	int32_t	i;
	t_map	m;

	m = data->map;
	i = -1;
	while (++i < m.height)
		free(m.points[i]);
	free(m.points);
	mlx_destroy_image(data->id, data->img.image);
	mlx_destroy_window(data->id, data->win);
	mlx_destroy_display(data->id);
	free(data->id);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**map;

	if (argc != 2)
		return (0);
	map = parse(argv[1]);
	if (!map)
		return (0);
	data.map = get_map(map);
	data.help = 1;
	data.offx = 0;
	data.offy = 0;
	data.dist = 6;
	data.view = 0;
	data.radius = 300;
	data.angleX = 45;
	data.angleY = 45;
	data.angleZ = 0;
	data.scale = 1.0;
	data.scale_h = 1.0;
	run(&data);
	return (0);
}
