#include "../includes/fdf.h"

int quit(t_data *data)
{
    int32_t i;
    t_map   m;

    m = data->map;
    i = -1;
    while (++i < m.height)
        free(m.points[i]);
    free(m.points);
    mlx_destroy_window(data->id, data->win);
    mlx_destroy_display(data->id);
    free(data->id);
    exit(EXIT_SUCCESS);
    return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    char    **map;

    if (argc != 2)
        return (0);
    map = parse(argv[1]);
    if (!map)
        return (0);
    data.map = get_map(map);
    window(&data);
    return (0);
}