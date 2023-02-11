#include "../includes/fdf.h"
#include "./gnl/get_next_line.h"

static int32_t   count_lines(char *path)
{
    int32_t fd;
    int32_t line;
    int32_t readc;
    char    buf;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (0);
    readc = 1;
    line = 0;
    while (readc)
    {
        readc = read(fd, &buf, 1);
        if (buf == '\n')
            ++line;
    }
    close(fd);
    return (line);
}

char    **parse(char *path)
{
    char    **map;
    int32_t i;
    int32_t line;
    int32_t fd;

    line = count_lines(path);
    if (!line)
        return (NULL);
    map = (char **)malloc(sizeof( char *) * (line + 1));
    if (!map)
        return (NULL);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    i = -1;
    while (++i <= line)
        map[i] = get_next_line(fd);
    close(fd);
    return (map);
}