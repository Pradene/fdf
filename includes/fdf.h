#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>

# include <stdlib.h>
# include <stdint.h>

# include <unistd.h>

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

// SUP
# include <stdio.h>
# include <string.h>

typedef struct s_point
{
    int32_t   y;
    int32_t   x;
    int32_t   z;
    int32_t   color;
}   t_point;

typedef struct s_map
{
    t_point     **points;
    int32_t    width;
    int32_t    height;
}   t_map;

typedef struct s_data
{
    void    *id;
    void    *win;
    t_map   map;
}   t_data;

// GNL
char	*get_next_line(int fd);

// PARSE
char    **parse(char *path);
void    free_map(char **map);

// COLOR
int32_t get_color(char *s);

// MAP
t_map   get_map(char **map);

// QUIT
int     quit(t_data *data);

// WINDOW
void    window(t_data *data);
int     key(int keycode, t_data *data);

#endif