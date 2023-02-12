#include "../includes/fdf.h"

static int32_t get_width(char *s)
{
    int32_t i;
    int32_t width;

    i = 0;
    width = 0;
    while (s[++i])
        if ((s[i] == ' ' || s[i] == '\0' || s[i] == '\n') && s[i - 1] != ' ')
            ++width;
    return (width);
}

static int32_t get_height(char **s)
{
    int32_t i;
    int32_t height;

    i = -1;
    height = 0;
    while (s[++i])
        ++height;
    return (height);
}

static int32_t get_next(char *s)
{
    int32_t i;

    i = 0;
    while (s[++i] && s[i] != '\n')
        if (s[i - 1] == ' ' && s[i] != ' ')
            break ;
    return (i);
}

t_point *get_point(char *s, int32_t height, int32_t width)
{
    t_point *points;
    int32_t i;
    int32_t j;

    i = -1;
    j = 0;
    points = (t_point *)malloc(sizeof(t_point) * (width));
    while (++i < width)
    {
        points[i].color = get_color(&s[j]);
        points[i].z = atoi(&s[j]);
        points[i].x = i;
        points[i].y = height;
        j += get_next(&s[j]);
    }
    return (points);
}

t_map   get_map(char **map)
{
    t_map   m;
    int32_t i;

    m.width = get_width(map[0]);
    m.height = get_height(map);
    m.points = (t_point **)malloc(sizeof(t_point *) * (m.height));
    i = -1;
    while (++i < m.height)
        m.points[i] = get_point(map[i], i, m.width);
    free_map(map);
    return (m);
}
