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

void	initialize_matrix(float matrix[4][4])
{
	matrix[0][0] = 0.36;
	matrix[0][1] = 0.48;
	matrix[0][2] = -0.8;
	matrix[0][3] = 0.0;
	matrix[1][0] = -0.8;
	matrix[1][1] = 0.6;
	matrix[1][2] = 0.0;
	matrix[1][3] = 0.0;
	matrix[2][0] = 0.48;
	matrix[2][1] = 0.65;
	matrix[2][2] = 0.6;
	matrix[2][3] = 0.0;
	matrix[3][0] = 0.0;
	matrix[3][1] = 0.0;
	matrix[3][2] = 0.0;
	matrix[3][3] = 1.0;
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
	data.offx = 0;
	data.offy = 0;
	data.distance = 32;
	data.angle = 0;
	data.view = 0;
	initialize_matrix(data.matrix);
	run(&data);
	return (0);
}
