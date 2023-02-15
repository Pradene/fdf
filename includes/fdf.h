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

// SUP
# include <stdio.h>
# include <string.h>

# define WIDTH 1280
# define HEIGHT 720
# define PI 3.14159265359

typedef struct s_pos
{
    int32_t x;
    int32_t y;
}   t_pos;

typedef struct s_gradient
{
    int32_t c1;
    int32_t c2;
}   t_gradient;

typedef struct s_point
{
    int32_t   y;
    int32_t   x;
    int32_t   z;
    int32_t   color;
}   t_point;

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
    t_point     **points;
    int32_t    width;
    int32_t    height;
}   t_map;

typedef struct s_data
{
    void        *id;
    void        *win;
    t_image     img;
    t_map       map;
    int32_t     offx;
    int32_t     offy;
    uint32_t    distance;
    uint32_t    angle;
    uint32_t    view;
    float       matrix[4][4];
    uint32_t    angleX;
    uint32_t    angleY;
    uint32_t    angleZ;
}   t_data;

// GNL
char	*get_next_line(int fd);

// PARSE
char    **parse(char *path);
void    free_map(char **map);

// COLOR
int32_t get_color(char *s);

// UTILS
int         get_max(int n1, int n2);
int         get_rgb(int c1, int c2, int percent);
t_gradient  get_gradient(int32_t c1, int32_t c2);
void	    render_line(t_data *data, t_pos p1, t_pos p2, t_gradient colors);
float	    get_radian(int angle);

// MAP
t_map   get_map(char **map);

// QUIT
int     quit(t_data *data);

// ISO
void	draw_iso(t_data *data);

// SPHERE
void    draw_sphere(t_data *data);

// WINDOW
void    run(t_data *data);
int     key(int keycode, t_data *data);
void    pixel_put(t_image *img, int x, int y, int color);

#endif