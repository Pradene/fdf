#include "../includes/fdf.h"

void    error(t_map *m, char *s)
{
    write(1, s, strlen(s));
    quit(m);
    exit(EXIT_FAILURE);
}