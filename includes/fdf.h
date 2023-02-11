#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>

# include <stdlib.h>
# include <stdint.h>

# include <unistd.h>

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

// GNL
char	*get_next_line(int fd);

// PARSE
char    **parse(char *path);

// COLOR
int32_t get_color(char *s);

// MAP
t_map   get_map(char **map);

#endif