/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:44:28 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/26 09:44:33 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>

# include <stdlib.h>
# include <stdint.h>

# include <unistd.h>

# include <math.h>
# include <time.h>

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265359

typedef struct s_pos
{
	int32_t	x;
	int32_t	y;
}	t_pos;

typedef struct s_gradient
{
	int32_t	c1;
	int32_t	c2;
}	t_gradient;

typedef struct s_point
{
	int32_t	y;
	int32_t	x;
	int32_t	z;
	int32_t	color;
}	t_point;

typedef struct s_image
{
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_map
{
	t_point		**points;
	int32_t		width;
	int32_t		height;
}	t_map;

typedef struct s_data
{
	void		*id;
	void		*win;
	t_image		img;
	t_map		map;
	uint32_t	view;
	int32_t		offx;
	int32_t		offy;
	uint32_t	dist;
	uint32_t	angle_x;
	uint32_t	angle_y;
	uint32_t	angle_z;
	int32_t		radius;
	float		scale;
	float		scale_h;
	int			help;
}	t_data;

// GNL
char		*get_next_line(int fd);

// PARSE
char		**parse(char *path);
void		free_map(char **map);
int32_t		parse_color(char *s);

// COLOR
int			get_pix_color(t_image *img, int x, int y);

// UTILS
int			get_max(int n1, int n2);
int			get_rgb(int c1, int c2, int percent);
t_gradient	get_gradient(int32_t c1, int32_t c2);
void		render_line(t_data *data, t_pos p1, t_pos p2, t_gradient colors);
float		rad(int angle);

// MAP
t_map		get_map(char **map);

// QUIT
int			quit(t_data *data);

// ISO
void		draw_iso(t_data *data);

// SPHERE
void		draw_sphere(t_data *data);
t_point		get_x(t_point p, float radian);
t_point		get_y(t_point p, float radian);
t_point		get_z(t_point p, float radian);

// HELP
void		help(t_data *data);

// WINDOW
void		run(t_data *data);
int			key(int keycode, t_data *data);
void		pixel_put(t_image *img, int x, int y, int color);

#endif
