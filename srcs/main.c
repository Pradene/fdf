#include "../includes/fdf.h"

void    quit(char **map)
{
    int32_t i;

    i = -1;
    while (map[++i])
        free(map[i]);
    free(map);
}

int main(int argc, char **argv)
{
    t_map   m;
    char    **map;

    if (argc != 2)
        return (0);
    map = parse(argv[1]);
    if (!map)
        return (0);
    m = get_map(map);
    quit(map);
    return (0);
}