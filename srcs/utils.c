#include "../includes/fdf.h"

int	get_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	get_rgb(int c1, int c2, int percent)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;

	r = (c1 >> (8 * 2) & 0xFF) + percent * ((c2 >> (8 * 2) & 0xFF)
			- (c1 >> (8 * 2) & 0xFF)) / 100;
	g = (c1 >> (8 * 1) & 0xFF) + percent * ((c2 >> (8 * 1) & 0xFF)
			- (c1 >> (8 * 1) & 0xFF)) / 100;
	b = (c1 >> (8 * 0) & 0xFF) + percent * ((c2 >> (8 * 0) & 0xFF)
			- (c1 >> (8 * 0) & 0xFF)) / 100;
	return ((r << (8 * 2)) + (g << (8 * 1)) + (b << (8 * 0)));
}

t_gradient  get_gradient(int32_t c1, int32_t c2)
{
    t_gradient  colors;

    colors.c1 = c1;
    colors.c2 = c2;
    return (colors);
}

void	render_line(t_data *data, t_pos p1, t_pos p2, t_gradient colors)
{
	int32_t	steps;
	int32_t	i;

   	if (abs(p1.x - p2.x) > abs(p1.y - p2.y))
		steps = abs(p1.x - p2.x);
	else
		steps = abs(p1.y - p2.y);
	i = -1;
	while (++i < steps)
	{
		pixel_put(&data->img,
			p1.x + (p2.x - p1.x) * i / steps,
			p1.y + (p2.y - p1.y) * i / steps,
			get_rgb(colors.c1, colors.c2, i * 100 / steps));
	}
}
