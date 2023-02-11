#include "../includes/fdf.h"

static int32_t parse_color(char *s, char *base)
{
    int32_t i;
    int32_t j;
    int32_t color;

    i = -1;
    color = 0;
    while (s[++i] != 'x')
        ;
    while (s[++i] != ' ')
    {
        j = -1;
        while (base[++j])
        {
            if (s[i] == base[j])
                break ;
        }
        color = color * strlen(base) + j;
    }
    return (color);
}

int32_t get_color(char *s)
{
    int32_t i;

    i = -1;
    while (s[++i] != ' ')
        if (s[i] == ',')
            return (parse_color(&s[i + 1], "0123456789ABCDEF"));
    return (-1);
}