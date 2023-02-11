#include "../includes/fdf.h"

void    pixel_put(t_image *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}